#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QObject>

class Calculator : public QObject {
    Q_OBJECT
    Q_PROPERTY(double sum READ sum NOTIFY sumChanged)
    Q_PROPERTY(double a READ a WRITE setA NOTIFY aChanged)
    Q_PROPERTY(double b READ b WRITE setB NOTIFY bChanged)

public:
    explicit Calculator(QObject* parent = nullptr);

    double sum() const;
    double a() const;
    double b() const;

signals:
    void sumChanged(double sum);
    void aChanged(double a);
    void bChanged(double b);

public slots:
    void setA(double a);
    void setB(double b);

private:
    double m_sum;
    double m_a;
    double m_b;

private slots:
    void calcualteSum();
};

#endif // CALCULATOR_H
