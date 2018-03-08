//
// Created by darsh on 3/1/2018.
//

#ifndef PROJECT_1_ROLE_H
#define PROJECT_1_ROLE_H

namespace hero{
    class Role{
    public:
        enum Type { FIGHTER, HEALER, TANK };
        Role (Type type);
        Role::Type get_type () const;
        operator std::string () const;

    };
}

#endif //PROJECT_1_ROLE_H
