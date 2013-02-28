/**
 ******************************************************************************
 *
 * @file       histogramdata.h
 * @author     Tau Labs, http://www.taulabs.org Copyright (C) 2013.
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup ScopePlugin Scope Gadget Plugin
 * @{
 * @brief The scope Gadget, graphically plots the states of UAVObjects
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef HISTOGRAMSCOPE_H
#define HISTOGRAMSCOPE_H

#include "scopes2d/scopes2dconfig.h"


/**
 * @brief The HistogramScope class The histogram scope has a variable sized list of
 * data sources
 */
class HistogramScope : public Scopes2d
{
    Q_OBJECT
public:
    HistogramScope();
    HistogramScope(QSettings *qSettings);
    HistogramScope(Ui::ScopeGadgetOptionsPage *options_page);
    ~HistogramScope();

    virtual void saveConfiguration(QSettings* qSettings);
    void create(QSettings qSettings);

    QList<Plot2dCurveConfiguration*> getHistogramDataSource(){return m_HistogramSourceConfigs;}
    void addHistogramDataSource(Plot2dCurveConfiguration* value){m_HistogramSourceConfigs.append(value);}
    void replaceHistogramDataSource(QList<Plot2dCurveConfiguration*> histogramSourceConfigs);

    //Getter functions
    virtual int getScopeType(){return (int) HISTOGRAM;}
    double getBinWidth(){return binWidth;}
    unsigned int getMaxNumberOfBins(){return maxNumberOfBins;}
    virtual QList<Plot2dCurveConfiguration*> getDataSourceConfigs(){return m_HistogramSourceConfigs;}

    //Setter functions
    void setBinWidth(double val){binWidth = val;}
    void setMaxNumberOfBins(unsigned int val){maxNumberOfBins = val;}

    virtual ScopesGeneric* cloneScope(ScopesGeneric *histogramSourceConfigs);

    virtual void setGuiConfiguration(Ui::ScopeGadgetOptionsPage *options_page);

    virtual void loadConfiguration(ScopeGadgetWidget *scopeGadgetWidget);

    virtual void preparePlot(ScopeGadgetWidget *);
    virtual void plotNewData(ScopeGadgetWidget *);
    virtual void clearPlots(ScopeGadgetWidget *scopeGadgetWidget);
    virtual void uavObjectReceived(UAVObject* obj, ScopeGadgetWidget *scopeGadgetWidget);

private:
    double binWidth;
    unsigned int maxNumberOfBins;
    QString units;

    QList<Plot2dCurveConfiguration*> m_HistogramSourceConfigs;

private slots:

};

#endif // HISTOGRAMSCOPE_H
