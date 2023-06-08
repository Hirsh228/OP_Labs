#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>


// Це все дефолт генерація QT, не звертай уваги.
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_find_btn_clicked()
{
    // Обробка виключення
    try {

        // Зчитування тексту з ui.
        std::string data = ui->file1->toPlainText().toStdString();
        std::string word = ui->word->text().toStdString();

        // Запис у файл тексту з ui
        TextFile file1("input.txt");
        file1.write(data);

        // Зчитування даних з записаного файлу для перевірки коректності.
        std::string filedata = file1.read();
        std::stringstream ss(filedata);
        std::string result = "";
        std::string line;
        std::string line_word;

        // Алгоритм для пошуку рядків, що містять слово.
        while (std::getline(ss, line)) {
            std::stringstream ss2(line);
            while (ss2 >> line_word) {
                if (word == line_word) {
                    result += line + '\n';
                    break;
                }
            }
        }

        // Запис результату у файл та його відображення.
        TextFile file2("output.txt");
        file2.write(result);
        std::string text = file2.read();

        ui->file2->setText(QString::fromStdString(text));
    } catch (const std::runtime_error& exception) {

        // Виведення вікна з помилкою у разі її виникнення.
        QMessageBox errorBox;
        errorBox.critical(0, "Error", exception.what());
        errorBox.show();
    }

}

