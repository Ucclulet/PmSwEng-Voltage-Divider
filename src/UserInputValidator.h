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
    /// \param \p unit String of units to be removed
    /// \param \p parent Sets up the validator. The parent parameter is passed on to the QObject constructor.
    ///
    UserInputValidator(const QString& unit, QObject* parent=0);

    ///
    /// \brief Validate the User-input to be valid values for the Formula.
    /// \param \p &input User-input data
    /// \param \p &pos 
    /// \return Returns QValidator::Acceptable if ok, otherwise QValidator::Intermediate
    /// 
    virtual State validate(QString &input, int &pos) const;

    ///
    /// \brief Getter for value
    /// \return Returns parameter \p value
    ///
    double getValue() const
    {
        return value;
    }

    ///
    /// \brief Getter for \p isValid
    /// \return Returns value of \p isValid
    ///
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
