#ifndef ALETHEIA_G_SESSION_H
#define ALETHEIA_G_SESSION_H
/* g_021CF7AC (arm9) */
struct Session {
    int state;
    int isinitialized;
    int reqid;
    int validated;
    char gamename[32];
    char secretkey[20];
    unsigned int key1;
    unsigned int key2;
    unsigned int key3;
    unsigned int key4;
    char *request;
    char *hash;
    char *data;
    void *resbuf;
    void *resbuflen;
    void *decodedbuf;
    unsigned int decodedbuflen;
    int (*callback)(unsigned int *, int);
    char lastHash[41];
};
#endif
