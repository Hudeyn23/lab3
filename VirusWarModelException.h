//
// Created by Nikita on 24.11.2020.
//

#ifndef LAB3_VIRUSWARMODELEXCEPTION_H
#define LAB3_VIRUSWARMODELEXCEPTION_H


#include <exception>
#include <string>

class VirusWarModelException : public ::std::exception {
private:
    std::string m_error;
public:
    VirusWarModelException(const std::string &error) {
        m_error = error;
    }

    const char *what() const noexcept { return m_error.c_str(); }
};


#endif //LAB3_VIRUSWARMODELEXCEPTION_H
