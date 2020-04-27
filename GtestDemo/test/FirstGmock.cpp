#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace sampleCXX {
namespace gmockDemo {

class FirstGmock {
public:
  virtual ~FirstGmock() = default;
  virtual void PenUp() = 0;
  virtual void PenDown() = 0;
  virtual void Forward(int distance) = 0;
  virtual void Turn(int degrees) = 0;
  virtual void GoTo(int x, int y) = 0;
  virtual int GetX() const = 0;
  virtual int GetY() const = 0;
};

class MockFirstGmock : public FirstGmock {
public:
	MockFirstGmock(int x, int y):m_x{x}, m_y{y} {

	}

	MOCK_METHOD0(PenUp, void());
//	MOCK_METHOD0(PenDown, void());
	MOCK_METHOD1(Forward, void(int));
	MOCK_METHOD1(Turn, void(int degrees));
	MOCK_METHOD2(GoTo, void(int, int));
	MOCK_CONST_METHOD0(GetX, int());
//	MOCK_CONST_METHOD0(GetY, int());

	void PenDown() override {
		std::cout << "PenDown Entry test!" << std::endl;
	}
	
	int GetY() const override {
		std::cout << "GetY Entry test!" << std::endl;
		return m_y;
	}

private:
	int m_x;
	int m_y;
};

TEST(MockFirstGmock, testGetY) {
	std::shared_ptr<MockFirstGmock> instance = std::make_shared<MockFirstGmock>(10,15);
	auto y = instance->GetY();
	EXPECT_EQ(15, y);
	EXPECT_CALL(*instance, GetX()).Times(1);
//	auto x = instance->GetX();
}

}
}
