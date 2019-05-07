#include <iostream>
#include <Memory.h>
#include "SharedUnique.h"

namespace sampleCXX {
namespace sharedUnique {

Base::Base(const std::string name):m_name{name} {
	std::cout << "name: " << m_name << std::endl;
}

std::string Base::getName() const {
	return m_name;
}

Base::~Base() {		
	std::cout << "destory base" << std::endl;
}

} // namespace sharedUnique
} // namespace sampleCXX

using namespace sampleCXX::sharedUnique;
using namespace sampleCXX;

//std::unique_ptr<Base> gloab_ins;
std::shared_ptr<Base> gloab_ins;

void getNameFunc(std::shared_ptr<Base> base) {
	std::cout << __func__ << " : usercount: " << base.use_count() << std::endl;
	std::cout << __func__ << " : name: " << base->getName() << std::endl;
	gloab_ins = base;
	base.reset();
	std::cout << __func__ << " : usercount: " << base.use_count() << " ins_usercount: " << gloab_ins.use_count() << std::endl;
	gloab_ins.reset();
}

int main() {
	//std::shared_ptr<Base> instance = std::make_shared<Base>("SvenBase");
	std::unique_ptr<Base> instance = common::make_unique<Base>("SvenBaseUnique");
	
	if(instance) {
		std::cout << __func__ << " : " << __LINE__ << std::endl;
		std::cout << __func__ << " : usercount: " << gloab_ins.use_count() << std::endl;
	//	std::cout << __func__ << " : usercount: " << instance.use_count() << std::endl;
	}
//	getNameFunc(instance);
	getNameFunc(std::move(instance));
	if(instance) {
		std::cout << __func__ << " : " << __LINE__ << std::endl;
	//	std::cout << __func__ << " : usercount: " << instance.use_count() << std::endl;
	}
		std::cout << __func__ << " : usercount: " << gloab_ins.use_count() << std::endl;
	return 0;
}

