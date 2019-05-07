#include <iostream>
#include <memory>
#include <gtest/gtest.h>

#include <Memory.h>

using namespace sampleCXX::common;

class Base {
public:
	Base(std::string name):m_name{name} {
		std::cout << "name: " << m_name << std::endl;
	}

	std::string getName() {
		return m_name;
	}
	~Base() {
		
		std::cout << "destory base" << std::endl;
	}
private:
	std::string m_name;
};

void getNameFunc(std::shared_ptr<Base> base) {
	std::cout << __func__ << " : usercount: " << base.use_count() << std::endl;
	std::cout << __func__ << " : name: " << base->getName() << std::endl;
	// EXPECT_EQ(2, base.use_count());
//	std::cout << __func__ << " : usercount: " << base.use_count() << " ins_usercount: " << gloab_ins.use_count() << std::endl;
}

TEST(Base, createInstance) {
	std::unique_ptr<Base> instance = make_unique<Base>("SvenBaseUnique");
	EXPECT_NE(instance, nullptr);
	instance.reset();
	EXPECT_EQ(instance, nullptr);
}

TEST(Base, getName) {
	std::unique_ptr<Base> instance = make_unique<Base>("BaseUnique");
	EXPECT_NE(instance, nullptr);
	auto name = instance->getName();
	EXPECT_STREQ(name.c_str(), "BaseUnique");
	instance.reset();
	EXPECT_EQ(instance, nullptr);
}

TEST(Base, shared_ptr) {
	std::shared_ptr<Base> instance = std::make_shared<Base>("BaseShared");
	EXPECT_NE(instance, nullptr);
	std::cout << "shared_ptr.use_count: " << instance.use_count() << std::endl;
	EXPECT_EQ(1, instance.use_count());
	getNameFunc(instance);
	EXPECT_EQ(1, instance.use_count());
}

TEST(Base, unique_ptr) {
	std::unique_ptr<Base> instance = make_unique<Base>("BaseUnique");
	EXPECT_NE(instance, nullptr);
	getNameFunc(std::move(instance));
	EXPECT_EQ(instance, nullptr);
}

