// database.h
#ifndef DATABASE_H
#define DATABASE_H

#include <string>

class Database {
public:
    virtual ~Database() = default;

    // Verifica si un usuario existe
    virtual bool userExists(const std::string& username) = 0;

    // Obtiene la contraseña de un usuario
    virtual std::string getPassword(const std::string& username) = 0;

    // Agrega un nuevo usuario
    virtual void addUser(const std::string& username, const std::string& password) = 0;
};

#endif // DATABASE_H
