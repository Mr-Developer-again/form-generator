#include <headers/formgenerator.h>
#include <headers/aradstyleformgenerator.h>

#include <stdexcept>
#include <QApplication>
#include <QMessageBox>

#include <algorithm>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString filePath = "/home/ali/projects/cpp_projects/Qt Projects/3.form_generator/src/sample.json";

    Arad::GeneratingForm::FormGenerator *formGenerator = nullptr;

    try
    {
        formGenerator = new Arad::GeneratingForm::AradStyleFormGenerator(filePath);
        formGenerator->darkTheme();
        formGenerator->setupForm();
    }
    catch (std::runtime_error const& ex)
    {
        QMessageBox mesgBx;
        mesgBx.setText(ex.what());
        mesgBx.setWindowTitle("runtime error");
        mesgBx.exec();
    }
    catch (std::invalid_argument const& ex)
    {
        QMessageBox mesgBx;
        mesgBx.setText(ex.what());
        mesgBx.setWindowTitle("invalid_argument error");
        mesgBx.exec();
    }

    return a.exec();
}
