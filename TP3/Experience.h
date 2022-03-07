#ifndef EXPERIENCE_H
#define EXPERIENCE_H
// à  faire : classe Interface
class Experience
{
public:
	virtual ~Experience() = default;
	virtual void afficher()  const = 0;
	virtual unsigned int obtenirExperience()   const = 0;
	virtual string obtenirNomExperience()  const = 0;

};
#endif
