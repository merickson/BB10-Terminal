/*
 * TerminalControl.cpp
 *
 *  Created on: Dec 6, 2014
 *      Author: matt
 */

#include "TerminalControl.h"

#include <QDebug>

#include <bb/cascades/Container>
#include <bb/cascades/HorizontalAlignment>
#include <bb/cascades/Label>
#include <bb/cascades/ScrollView>
#include <bb/cascades/ScrollAnimation>
#include <bb/cascades/SystemDefaults>
#include <bb/cascades/TextStyle>

#include <ft2build.h>
#include FT_FREETYPE_H

using namespace bb::cascades;

TerminalControl::TerminalControl(Container *parent)
    : CustomControl(parent)
{
    m_rootContainer = new Container();

    m_scrollView = new ScrollView();
    m_scrollView->setHorizontalAlignment(HorizontalAlignment::Fill);

    m_label = new Label();
    m_label->setMultiline(true);
    m_label->setHorizontalAlignment(HorizontalAlignment::Fill);
    setTerminalFace();

    m_scrollView->setContent(m_label);
    m_rootContainer->add(m_scrollView);

    setRoot(m_rootContainer);
}


TerminalControl::~TerminalControl()
{
    // TODO Auto-generated destructor stub
}

void TerminalControl::update(QString data)
{
    m_label->setText(data);
}

void TerminalControl::calculateFaceSize()
{
    // For now, we're assuming a Q10 screen DPI of 360.
    // TODO: do better later.
    float dpi = 360.0f;
    float pt_size = 12.0f;

    FT_Library library;
    int error = FT_Init_FreeType(&library);
    if (error) {
        qDebug() << "failed to load FreeType library";
    }

    FT_Face face;
    error = FT_New_Face(library, "/usr/fonts/font_repository/dejavu/DejaVuSansMono.ttf", 0, &face);
    if (error == FT_Err_Unknown_File_Format) {
        qDebug() << "Failed file format";
    } else if (error) {
        qDebug() << "Something broke loading the font";
    }

    error = FT_Set_Char_Size(face, pt_size * 64, pt_size * 64, dpi, dpi);

    qDebug() << "We have " << face->num_glyphs << " glyphs available for " << face->family_name;
}

void TerminalControl::setTerminalFace()
{
    TextStyle monospaceStyle = TextStyle(SystemDefaults::TextStyles::bodyText());
    monospaceStyle.setFontFamily("\"DejaVu Sans Mono\", monospace");

    m_label->textStyle()->setBase(monospaceStyle);

    calculateFaceSize();
}
