#include <iostream>
#include <memory>
#include <gtest/gtest.h>

#include <Memory.h>

using namespace sampleCXX::common;

class Base {
public:
	Base(std::string name):m_name{name} {
		std::cout << "Create constructor name: " << m_name << std::endl;
	}

	std::string getName() {
		return m_name;
	}

	void setName(const std::string &name) {
		m_name = std::string(name);
	}

	~Base() {
		
		std::cout << "Destory base" << std::endl;
	}
private:
	std::string m_name;
};


class BaseTest : public ::testing::Test {
protected:
	void SetUp() override {
		m_base = std::make_shared<Base>("SvenBaseTest");
	}

	void TearDown() override {
		m_base.reset();
	}

	std::shared_ptr<Base> m_base;
};

TEST_F(BaseTest, testCreateInstance) {
	std::unique_ptr<Base> instance = make_unique<Base>("SvenBaseUnique");
	EXPECT_NE(instance, nullptr);
	instance.reset();
	EXPECT_EQ(instance, nullptr);
}

TEST_F(BaseTest, testGetName) {
	auto name = m_base->getName();
	EXPECT_STREQ(name.c_str(), "SvenBaseTest");
}

TEST_F(BaseTest, testSetName) {
	m_base->setName("NewSvenBase");
	auto name = m_base->getName();
	EXPECT_STREQ(name.c_str(), "NewSvenBase");
}

