#include "ComboProperty.h"


ComboProperty::ComboProperty(const QStringList &values, const QString &current_value)
    : m_values(values)
    , m_current_value(current_value)
{

}


void ComboProperty::setValue(const QString &name)
{
    Q_ASSERT(m_values.contains(name));
    m_current_value = name;
}

int ComboProperty::index() const
{
    return toIndex(m_current_value);
}

int ComboProperty::toIndex(const QString &value) const
{
    QStringList name_list = getValues();
    for (int i = 0; i < name_list.size(); ++i) {
        if (value == name_list[i]) {
            return i;
        }
    }
    return -1;
}

QString ComboProperty::toString(int index) const
{
    QStringList name_list = getValues();
    if (index<0 || index>=name_list.size()) {
        return QString();
    }
    return name_list[index];
}
