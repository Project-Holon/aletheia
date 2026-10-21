#ifndef GAME_OV114_GHTTPPOST_H
#define GAME_OV114_GHTTPPOST_H

typedef enum { GHIPostingError, GHIPostingDone, GHIPostingWaitForContinue } GHIPostingResult;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ghttppost.c, prototypes copied from their definitions. */

struct GHIPost;
struct GHIConnection;

#include "../ov114/ghttp_types.h"

void ghiPostDataFree(void *element);
GHIPost *ghiNewPost(void);
void ghiPostSetAutoFree(GHIPost *post, GHTTPBool autoFree);
void ghiFreePost(GHIPost *post);
void ghiFreePostAndUpdateConnection(int request, GHIPost *post);
int ghiPostAddFileFromMemory(GHIPost *_post, char *name, char *buffer, int bufferLen, char *reportFilename, char *contentType);
int ghiPostAddXml(struct GHIPost *_post, void *xml);
char *ghiPostGetContentType(struct GHIConnection *connection);
int ghiPostGetNoFilesContentLength(GHIConnection *connection);
int ghiPostGetHasFilesContentLength(GHIConnection *connection);
int ghiPostGetContentLength(GHIConnection *connection);
int ghiPostStateInit(GHIPostState *state);
int ghiPostInitState(GHIConnection *connection);
void ghiPostCleanupState(GHIConnection *connection);
GHIPostingResult ghiPostStringStateDoPosting(GHIPostState *state, GHIConnection *connection);
GHIPostingResult ghiPostXmlStateDoPosting(GHIPostState *state, GHIConnection *connection);
int ghiPostFileDiskStateDoPosting(GHIPostState *state, GHIConnection *connection);
int ghiPostFileMemoryStateDoPosting(GHIPostState *state, GHIConnection *connection);
int ghiPostDoPosting(GHIConnection *connection);
/* END mkheaders: generated region */

#endif
