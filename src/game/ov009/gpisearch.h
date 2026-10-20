#ifndef GAME_OV009_GPISEARCH_H
#define GAME_OV009_GPISEARCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpisearch.c, prototypes copied from their definitions. */

#include "../ov009/gpi_types.h"

int gpiStartProfileSearch(void **connection, GPIOperation *operation);
int gpiInitSearchData(void **connection, GPISearchData **out, int type);
int gpiStartSearch(void **connection, GPISearchData *data, int blocking, GPCallback callback, void *param);
int gpiProfileSearch(void **connection, char *nick, char *uniquenick, char *email, char *firstname, char *lastname, int icquin, int skip, int blocking, GPCallback callback, void *param);
int gpiOthersBuddyList(void **connection, int *profiles, int numOfProfiles, int blocking, void (*callback)(void **, void *, void *), void *param);
GPResult gpiProcessSearch(GPConnection *connection, GPIOperation *operation);
int gpiProcessSearches(void **connection);
/* END mkheaders: generated region */

#endif
