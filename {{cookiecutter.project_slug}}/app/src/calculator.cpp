#include "calculator.h"

Calculator::Calculator(QObject* parent)
    : QObject(parent)
    , m_sum(0.0)
    , m_a(0.0)
    , m_b(0.0)
{
    connect(this, &Calculator::aChanged,
        this, &Calculator::calcualteSum);
    connect(this, &Calculator::bChanged,
        this, &Calculator::calcualteSum);
}

double Calculator::sum() const
{
    return m_sum;
}

double Calculator::a() const
{
    return m_a;
}

double Calculator::b() const
{
    return m_b;
}

void Calculator::setA(double a)
{
    if (qFuzzyCompare(m_a, a))
        return;

    m_a = a;
    emit aChanged(m_a);
}

void Calculator::setB(double b)
{
    if (qFuzzyCompare(m_b, b))
        return;

    m_b = b;
    emit bChanged(m_b);
}

void Calculator::calcualteSum()
{
    m_sum = m_a + m_b;
    emit sumChanged(m_sum);
}
