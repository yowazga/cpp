#include <iostream>
#include <string>

class ICharacter;

class AMateria {
protected:
    std::string type;

public:
    AMateria(std::string const& type);
    virtual ~AMateria();
    std::string const& getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

class Ice : public AMateria {
public:
    Ice();
    AMateria* clone() const ;
    void use(ICharacter& target) ;
};

class Cure : public AMateria {
public:
    Cure();
    AMateria* clone() const ;
    void use(ICharacter& target) ;
};

class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const& getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];

public:
    Character(std::string const& name);
    Character(const Character& other); // Deep copy constructor
    Character& operator=(const Character& other); // Deep copy assignment operator
    ~Character();
    std::string const& getName() const ;
    void equip(AMateria* m) ;
    void unequip(int idx) ;
    void use(int idx, ICharacter& target) ;
};

class IMateriaSource {
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria* m) = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};

class MateriaSource : public IMateriaSource {
private:
    AMateria* learnedMaterias[4];
    int numLearnedMaterias;

public:
    MateriaSource();
    ~MateriaSource();
    void learnMateria(AMateria* m) ;
    AMateria* createMateria(std::string const& type) ;
};

// AMateria implementation
AMateria::AMateria(std::string const& type) : type(type) {}
AMateria::~AMateria() {}
std::string const& AMateria::getType() const {
    return type;
}
void AMateria::use(ICharacter& target) {
    (void)target; // Avoid "unused parameter" warning
}

// Ice implementation
Ice::Ice() : AMateria("ice") {}
AMateria* Ice::clone() const {
    return new Ice(*this);
}
void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

// Cure implementation
Cure::Cure() : AMateria("cure") {}
AMateria* Cure::clone() const {
    return new Cure(*this);
}
void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

// Character implementation
Character::Character(std::string const& name) : name(name) {
    for (int i = 0; i < 4; ++i) {
        inventory[i] = nullptr;
    }
}
Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i]) {
            inventory[i] = other.inventory[i]->clone();
        } else {
            inventory[i] = nullptr;
        }
    }
}
Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; ++i) {
            if (inventory[i]) {
                delete inventory[i];
            }
            if (other.inventory[i]) {
                inventory[i] = other.inventory[i]->clone();
            } else {
                inventory[i] = nullptr;
            }
        }
    }
    return *this;
}
Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        if (inventory[i]) {
            delete inventory[i];
        }
    }
}
std::string const& Character::getName() const {
    return name;
}
void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
}
void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        inventory[idx] = nullptr;
    }
}
void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    }
}

// MateriaSource implementation
MateriaSource::MateriaSource() : numLearnedMaterias(0) {
    for (int i = 0; i < 4; ++i) {
        learnedMaterias[i] = nullptr;
    }
}
MateriaSource::~MateriaSource() {
    for (int i = 0; i < numLearnedMaterias; ++i) {
        delete learnedMaterias[i];
    }
}
void MateriaSource::learnMateria(AMateria* m) {
    if (numLearnedMaterias < 4) {
        learnedMaterias[numLearnedMaterias++] = m;
    }
}
AMateria* MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < numLearnedMaterias; ++i) {
        if (learnedMaterias[i]->getType() == type) {
            return learnedMaterias[i]->clone();
        }
    }
    return nullptr; // Type not found
}

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;
}
