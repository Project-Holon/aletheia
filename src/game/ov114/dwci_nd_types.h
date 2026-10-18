/* Shared types of the DWC download (nd) module: dwc_nd, dwci_nd. */
#ifndef DWCI_ND_TYPES_H
#define DWCI_ND_TYPES_H

#ifndef OV114_BASIC_TYPES
#define OV114_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#endif

typedef void *(*NdAlloc)(unsigned int size, int align);

typedef void (*NdFree)(void *p);

typedef void (*DWCNdCallback)(int reason, int err, int servererror);

/* One entry of the downloadable file list (0xb0 bytes). */
typedef struct DWCNdFileInfo {
    char name[33];
    short explain[51];
    char param1[11];
    char param2[11];
    char param3[11];
    unsigned int size;
} DWCNdFileInfo;

/* Request context of one nd HTTP transaction. */
typedef struct tagDWCi_Ndi_HTTPREQ {
    int reason;                 /* +0x00, 1 count, 2 list, 3 file */
    DWCNdCallback callback;        /* +0x04 */
    void *threadEvent;          /* +0x08 */
    union {
        struct {
            char *encName;      /* +0x0c */
            int size;           /* +0x10 */
        } getfile;
        struct {
            DWCNdFileInfo *filelist;
            int num;
            char *pBuf;
            char *strOffset;
            char *strNum;
        } list;
        struct {
            int *count;
        } getcount;
        char pad[20];
    } param;
} tagDWCi_Ndi_HTTPREQ;

/* File statics of dwci_nd.o. */
typedef struct NdStatics {
    DWCNdCallback callback;    /* +0x00 */
    NdAlloc alloc;          /* +0x04 */
    int initialized;        /* +0x08 */
    int apinfo;             /* +0x0c */
    void *handle;           /* +0x10 */
    NdFree free;            /* +0x14 */
    char *token;            /* +0x18 */
    char *url;              /* +0x1c */
    int httpCallbackBusy;   /* +0x20 */
    void (*cleanup)(void);  /* +0x24 */
    char pad28[0x3c - 0x28];
    char *attr1;            /* +0x3c */
    char *attr2;            /* +0x40 */
    char *attr3;            /* +0x44 */
} NdStatics;

extern NdStatics gDwciNdStatics;
extern char gDwciNdHttpMutex[];

#endif
