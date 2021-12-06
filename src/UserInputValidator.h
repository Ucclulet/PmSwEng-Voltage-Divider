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
    ///
    /// \brief UserInputValidator Ctor
    /// \param unit String of units to be removed
    /// \param parent Sets up the validator. The parent parameter is passed on to the QObject constructor.
    ///
    UserInputValidator(const QString& unit, QObject* parent=0);

    ///
    /// \brief Validate the User-input to be valid values for the Formula.
    /// \param &input User-input data
    /// \param &pos 
    /// \return returns QValidator::Acceptable if ok, otherwise QValidator::Intermediate
    /// 
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
