#include "mainwindow.h"
#include "ui_mainwindow.h"

double first_number;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->n_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->n_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->n_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->n_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->n_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->n_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->n_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->n_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->n_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->n_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->mod, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->div, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->mul, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->plus, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->div->setCheckable(true);
    ui->mul->setCheckable(true);
    ui->minus->setCheckable(true);
    ui->plus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;
    all_numbers = (ui->result->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 15);

    ui->result->setText(new_label);
}

void MainWindow::on_point_clicked()
{
    if (!(ui->result->text().contains('.')))
        ui->result->setText(ui->result->text() + '.');
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if (button->text() == "+/-")
    {
        all_numbers =(ui->result->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->result->setText(new_label);
    }
    if (button->text() == "%")
    {
        all_numbers =(ui->result->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->result->setText(new_label);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();
    button->setChecked(true);
    first_number = (ui->result->text()).toDouble();
    ui->result->setText("");
}

void MainWindow::on_equal_clicked()
{
    double label_num, second_num;
    QString new_label;

    second_num = (ui->result->text()).toDouble();

    if (ui->div->isChecked())
    {
        if (second_num != 0)
        {
            label_num = first_number / second_num;
            new_label = QString::number(label_num, 'g', 15);
            ui->result->setText(new_label);
        }
        else
        {
            new_label = "0";
            ui->result->setText(new_label);
        }

        ui->div->setChecked(false);
    }

    if (ui->mul->isChecked())
    {
        label_num = first_number *second_num;
        new_label = QString::number(label_num, 'g', 15);
        ui->result->setText(new_label);

        ui->mul->setChecked(false);
    }

    if (ui->minus->isChecked())
    {
        label_num = first_number - second_num;
        new_label = QString::number(label_num, 'g', 15);
        ui->result->setText(new_label);

        ui->minus->setChecked(false);
    }

    if (ui->plus->isChecked())
    {
        label_num = first_number + second_num;
        new_label = QString::number(label_num, 'g', 15);
        ui->result->setText(new_label);

        ui->plus->setChecked(false);
    }

    first_number = label_num;

}

void MainWindow::on_clear_clicked()
{
    first_number = 0;
    ui->result->setText("");

}
