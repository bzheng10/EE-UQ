#ifndef _STOCHASTIC_MODEL_WIDGET_H
#define _STOCHASTIC_MODEL_WIDGET_H

/* *****************************************************************************
Copyright (c) 2016-2017, The Regents of the University of California (Regents).
All rights reserved.

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the FreeBSD Project.

REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED HEREUNDER IS 
PROVIDED "AS IS". REGENTS HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, 
UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

*************************************************************************** */

// Written: mhgardner
#include <QJsonObject>
#include <QString>
#include <QWidget>
#include <RandomVariablesContainer.h>
#include <SimCenterWidget.h>

// Forward declarations
class QJsonObject;
class QString;
class QWidget;
class RandomVariablesContainer;

/**
 * Widget for inputting parameters for stochastic earthquake time history
 * generation model
 */
class StochasticModelWidget : public SimCenterWidget {
  Q_OBJECT
 public:
  /**
   * @constructor Construct new stochastic model input widget
   * @param[in, out] random_variables Widget to store random variables to
   * @param[in, out] parent Pointer to parent widget. Defaults to nullptr.
   */
  explicit StochasticModelWidget(RandomVariablesContainer* random_variables,
                                 QWidget* parent = nullptr);

  /**
   * @destructor Virtual desctructor for stochastic model input widget
   */
  virtual ~StochasticModelWidget() {};

  /**
   * Instantiate stochastic motion input widget from input JSON object
   * @param[in] rvObject JSON object containing input information
   * @return Returns true if successful, false otherwise
   */
  virtual bool inputFromJSON(QJsonObject& rvObject) = 0;

  /**
   * Write all current class data to JSON required to reconstruct class
   * @param[in, out] rvObject JSON object to write output to
   * @return Returns true if successful, false otherwise
   */
  virtual bool outputToJSON(QJsonObject& rvObject) = 0;

 signals:
  void sendErrorMessage(QString message);

 public slots:
  /**
   * Emit error message displaing input message
   * @param[in] message String containg error message to emit
   */
   virtual void errorMessage(QString message);

 protected:
  RandomVariablesContainer* rv_input_widget_; /**< Widget for inputting random
						  variables */
};

#endif  // _STOCHASTIC_MODEL_WIDGET_H
