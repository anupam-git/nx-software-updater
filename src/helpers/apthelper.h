
#ifndef HELPERS_APTHELPER_H
#define HELPERS_APTHELPER_H

#include <QList>
#include <QObject>
#include <string>

#include "../dto/packagedto.h"
#include "../listeners/packagelistlistener.h"
#include "shellhelper.h"

using namespace std;

class AptHelper : public QObject {
  Q_OBJECT

 public:
  AptHelper(QObject* parent = nullptr);
  virtual ~AptHelper();

  QList<PackageDTO*> aptList();
  void aptUpdate();
  void aptUpgrade();

 public slots:
  void onRunAptList();
  void onRunAptUpdate();
  void onRunAptUpgrade();

 signals:
  void onAptListComplete(QList<PackageDTO*> packageList);
  void onAptUpdateComplete();
  void onAptUpgradeComplete();

 private:
  QList<PackageDTO*> parsePackageListFile(std::string path);
  ShellHelper* shellHelper;
  string storageBasePath;
};

#endif
