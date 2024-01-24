//
//  main.c
//
//  Created by Reed Spool and Quinten Konyn!
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "pd_api.h"

static PlaydateAPI *pd = NULL;

static int update(void *ud) {
  // NOTE: Keeping these around from the Game of Life because I'm worried that
  // we'll forget to `markUpdatedRows` if we ever do frame twiddling ourselves
  /* uint8_t* nextframe = pd->graphics->getFrame(); // working buffer */
  // we twiddled the framebuffer bits directly, so we have to tell the system
  // about it
  /* pd->graphics->markUpdatedRows(0, LCD_ROWS); */

  double angleDegrees = (double)pd->system->getCrankAngle();
  double angle = (angleDegrees * 2 * M_PI) / 360;
  int centerX = 400 / 2;
  int centerY = 280 / 2;
  // Should be the pythagorean theorm for the cente rpoint
  int radius = 400;
  pd->graphics->drawLine(centerX + (cos(angle) * radius),
                         centerY - (sin(angle) * radius),
                         centerX - (cos(angle) * radius),
                         centerY + (sin(angle) * radius), 1, kColorBlack);
  return 1;
}

#ifdef _WINDLL
__declspec(dllexport)
#endif
    int eventHandler(PlaydateAPI *playdate, PDSystemEvent event, uint32_t arg) {
  if (event == kEventInit) {
    pd = playdate;
    pd->display->setRefreshRate(0); // run as fast as possible
    pd->system->setUpdateCallback(update, NULL);
  }

  return 0;
}
