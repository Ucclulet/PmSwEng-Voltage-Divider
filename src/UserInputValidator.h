///
/// \file UserInputValidator.h
/// \date 30.11.2016
/// \author Michael Trummer
///

#ifndef USERINPUTVALIDATOR_H
#define USERINPUTVALIDATOR_H

#include <QValidator>

class UserInputValidator : public QValidator
{
public:

    UserInputValidator(const QString& unit, QObject* parent=0);

    virtual State validate(QString &input, int &pos) const;

    double getValue() const
    {
        return value;
    }

    bool getIsValid() const
    {
        return isValid;
    }
private:
    const QString unit;
    mutable double value;
    mutable bool isValid;
};

#endif // USERINPUTVALIDATOR_H
