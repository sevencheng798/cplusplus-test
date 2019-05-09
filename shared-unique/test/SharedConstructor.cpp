#include <iostream>
#include <gtest/gtest.h>

TEST(Shared, Constructor) {
	std::shared_ptr<int> sp1(new int(10));
	std::shared_ptr<int> sp2(sp1), sp3;
	EXPECT_EQ(2, sp1.use_count());
	EXPECT_EQ(2, sp2.use_count());
	EXPECT_EQ(0, sp3.use_count());

	sp3 = sp1;	
	EXPECT_EQ(3, sp1.use_count());
	EXPECT_EQ(3, sp2.use_count());
	EXPECT_EQ(3, sp3.use_count());
	// 一个典型的错误用法
	//sp1.get()的返回值就相当于一个裸指针的值，不合适的使用这个值
	//std::shared_ptr<int> sp4(sp1.get());

	EXPECT_EQ(3, sp1.use_count());
	EXPECT_EQ(3, sp2.use_count());
	EXPECT_EQ(3, sp3.use_count());
//	EXPECT_EQ(1, sp4.use_count());
	
	sp1.reset();
	EXPECT_EQ(0, sp1.use_count());
	EXPECT_EQ(2, sp2.use_count());
	EXPECT_EQ(2, sp3.use_count());
//	EXPECT_EQ(1, sp4.use_count());
}
