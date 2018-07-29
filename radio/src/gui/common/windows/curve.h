/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */


#ifndef _CURVE_H_
#define _CURVE_H_

#include "window.h"

class CurveWindow: public Window {
  public:
    CurveWindow(Window * parent, const rect_t & rect, std::function<int(int)> function, std::function<int()> position=nullptr):
      Window(parent, rect),
      function(function),
      position(position)
    {
    }

    virtual void checkEvents() override
    {
      // will always force a full window refresh
      if (position)
        invalidate();
    }

    virtual void paint(BitmapBuffer * dc) override;

  protected:
    std::function<int(int)> function;
    std::function<int()> position;
    void drawBackground(BitmapBuffer * dc);
    void drawCurve(BitmapBuffer * dc);
    void drawPosition(BitmapBuffer * dc);
    coord_t getPointX(int x);
    coord_t getPointY(int y);
};

#endif // _CURVE_H_