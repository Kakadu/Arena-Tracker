#ifndef SCOREBUTTON_H
#define SCOREBUTTON_H

#include <QObject>
#include <QPushButton>
#include "../utility.h"

class ScoreButton : public QPushButton
{
    Q_OBJECT

//Constructor
public:
    ScoreButton(QWidget * parent, DraftMethod draftMethod, bool normalizedLF);

//Variables
private:
    double score;
    bool learningMode, learningShow;
    bool isBestScore;
    DraftMethod draftMethod;
    bool normalizedLF;

//Metodos
private:
    void getScoreColor(int &r, int &g, int &b, double score);
    void draw();

protected:
    void enterEvent(QEvent *e) Q_DECL_OVERRIDE;
    void leaveEvent(QEvent *e) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

public:
    void setScore(double score, bool isBest);
    void setLearningMode(bool value);
    void setLearningShow(bool value);
    void setNormalizedLF(bool value);

signals:
    void spreadLearningShow(bool value);
};

#endif // SCOREBUTTON_H
