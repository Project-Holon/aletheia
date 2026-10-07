#ifndef ALETHEIA_G_NNTHINKGLOBAL_H
#define ALETHEIA_G_NNTHINKGLOBAL_H
/* g_021AAA20 (arm9) */
struct DWCstMatchControl;
struct NNThinkGlobal {
    int bInNNThink;
    struct DWCstMatchControl *pMatch;
    int bNNFreeNegotiateList;
    char *addFilter;
    int needSbFree;
    int sbCallbackLevel;
};
#endif
