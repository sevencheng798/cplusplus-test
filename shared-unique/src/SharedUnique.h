/**
 * Creator 2019-05-07
 */

#include <memory>

namespace sampleCXX {
namespace sharedUnique {

class Base {
public:
	/// Constructor.
	Base(const std::string name);

	/// Get the member of @c m_name.
	std::string getName() const;
	
	/// Destructor.
	~Base();
		
private:
	const std::string m_name;
};

} // namespace sharedUnique
} // namespace sampleCXX
