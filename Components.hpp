#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

class Components{
    protected:
        Components();
        virtual int encode(int input) = 0;
        int *mapToLetters;

};

#endif // COMPONENTS_HPP
