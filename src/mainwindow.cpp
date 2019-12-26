#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qclipboard.h>

#include <iostream>
#include <string>

#include "matheval.hpp"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	connect(ui->line, &QLineEdit::textChanged, this, &MainWindow::eval);
	connect(ui->line, &QLineEdit::returnPressed, this, &MainWindow::eval);
	connect(ui->eval, &QPushButton::pressed, this, &MainWindow::eval);
	connect(ui->copy, &QPushButton::pressed, this, &MainWindow::copy);
}

MainWindow::~MainWindow()
{
}

void MainWindow::eval()
{
	QString qstr = ui->line->text();
	std::string str = qstr.toUtf8().constData();
	if (!str.empty()) {
		try {
			double res = matheval::parse(str, {});
			ui->res->setText(QString::number(res, format, precision));
		}
		catch (std::exception const& e) {
			ui->res->setText(error + e.what());
		}
	}
	else {
		ui->res->clear();
	}
}

void MainWindow::copy()
{
	QClipboard* clipboard = QApplication::clipboard();
	auto str = ui->res->text();
	clipboard->setText(str, QClipboard::Clipboard);

	if (clipboard->supportsSelection()) {
		clipboard->setText(str, QClipboard::Selection);
	}
}


