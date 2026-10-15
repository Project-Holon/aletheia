/*
 * nns_fnd_types.h: shared NitroSystem foundation (NNS_Fnd) types.
 *
 * Owner header for the heap head record and the list/link records the fnd
 * heap implementations share: nns_fnd_expheap.c, nns_fnd_frameheap.c,
 * nns_fnd_unitheap.c, and the sound archive heap code that carries an
 * NNSFndHeapHandle (nns_snd_arc_types.h).
 *
 * Base integer typedefs are intentionally not declared here: every arm9 file
 * still declares its own, and a second typedef of the same name is a C99
 * constraint violation.  The raw types keep the layout identical.
 */
#ifndef NNS_FND_TYPES_H
#define NNS_FND_TYPES_H

typedef struct NNSFndLink {
    void *prevObject;
    void *nextObject;
} NNSFndLink;

typedef struct NNSFndList {
    void *headObject;
    void *tailObject;
    unsigned short numObjects;
    unsigned short offset;
} NNSFndList;

typedef struct NNSiFndHeapHead {
    unsigned int signature;
    NNSFndLink   link;
    NNSFndList   childList;
    void *heapStart;
    void *heapEnd;
    unsigned int attribute;
} NNSiFndHeapHead;

typedef NNSiFndHeapHead *NNSFndHeapHandle;

#endif
