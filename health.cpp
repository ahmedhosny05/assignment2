#include "health.h"
#include "ui_health.h"

Health::Health(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Health)
{
    ui->setupUi(this);

    // Initialize health value
    healthValue = 100; // Example initial health value, adjust as needed

    // Update the displayed health value
    updateHealthLabel();
}

Health::~Health()
{
    delete ui;
}

void Health::decreaseHealth(int amount)
{
    // Decrease health by the specified amount
    healthValue -= amount;

    // Ensure health doesn't go below 0
    healthValue = qMax(healthValue, 0);

    // Update the displayed health value
    updateHealthLabel();
}

int Health::getHealth()
{
    return healthValue;
}

void Health::updateHealthLabel()
{
    // Update the displayed health value in the UI
    ui->healthLabel->setText(QString("Health: %1").arg(healthValue));
}
