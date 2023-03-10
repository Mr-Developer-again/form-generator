#ifndef ARAD_GENERATINGFORM_FORMGENERATOR_FORMGENERATOR_H
#define ARAD_GENERATINGFORM_FORMGENERATOR_FORMGENERATOR_H

#include <headers/jsonparser.h>

#include <QWidget>
#include <QString>
#include <QMainWindow>

namespace Arad
{
    namespace GeneratingForm
    {

        class FormGenerator : public QMainWindow
        {
        public:
            explicit FormGenerator(QString const& filePath, QWidget *parent = nullptr);
            virtual ~FormGenerator();

            virtual void setupForm() = 0;

            /// this method loads some file and colorize the main widget
            /// (and also changes style of the widget)
            virtual void darkTheme();
        protected:
            virtual void setFilePath(QString const& filePath);
            virtual QString getFilePath() const noexcept;

            QWidget* _widget = nullptr;
            Arad::Parser::JsonParser *_jsonParser = nullptr;

            virtual bool validInteger(QString const& inputString) const noexcept;
            virtual bool validDouble(QString const& inputString) const noexcept;

        private:
            QString _filePath = "";
        };

    } // GeneratingForm namespace

} // Arad namespace


#endif // ARAD_GENERATINGFORM_FORMGENERATOR_FORMGENERATOR_H
