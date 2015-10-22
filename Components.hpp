#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <memory>
class Components
{
    public:
        Components(shared_ptr <int> table);
    protected:
    private:
        int *table = nullptr;
};

#endif // COMPONENTS_HPP
