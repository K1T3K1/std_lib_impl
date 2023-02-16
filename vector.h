#ifndef VECTOR_H_
#define VECTOR_H_

#include <memory>
#include <vector>

namespace _std {
template <typename T>
struct Vector {
        Vector(){};
        Vector(const T&...values){

        }

        Vector(const T&&...values){

        }

        void vector_allocate(const T&...values){
            begin_ptr = std::make_unique<T[]>(sizeof...(values));
            int allocation_iterator = 0;
            for(auto value : values){
                *begin_ptr =
            }
        }

        T operator[](unsigned int index){
            return vec_span[index];
        }
    private:

};
}  // namespace _std
#endif VECTOR_H_