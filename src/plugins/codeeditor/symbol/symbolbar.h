// SPDX-FileCopyrightText: 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef SYMBOLBAR_H
#define SYMBOLBAR_H

#include <QVariant>
#include <QWidget>

class CurmbItem : public QWidget
{
    Q_OBJECT
public:
    enum CurmbType {
        FilePath,
        Symbol
    };

    explicit CurmbItem(CurmbType type, int index, QWidget *parent = nullptr);

    CurmbType curmbType() const;
    void setText(const QString &text);
    void setSelected(bool selected);
    bool isRoot() const;
    void setUserData(const QVariant &data);
    QVariant userData() const;

Q_SIGNALS:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    QString displayText;
    int index { 0 };
    int spacing { 5 };
    bool isSelected { false };
    bool isHover { false };
    QVariant data;
    CurmbType type;
};

class SymbolView;
class SymbolBar : public QWidget
{
    Q_OBJECT
public:
    explicit SymbolBar(QWidget *parent = nullptr);

    void setPath(const QString &path);
    void clear();

public Q_SLOTS:
    void updateSymbol(int line, int index);
    void curmbItemClicked();

private:
    CurmbItem *symbolItem { nullptr };
    SymbolView *symbolView { nullptr };
};

#endif   // SYMBOLBAR_H