/*
 * function: func_020604AC
 * address:  0x020604AC
 * packet:   pkt_0205D1BC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02060480  0x02060480  arm
 *
 * NitroSystem fnd/list.c, NNS_FndAppendListObject (append at the tail).  The library was identified from
 * the shape (head, tail, u16 count, u16 link offset) and the body follows the
 * public NitroSystem source: the link address is formed in u32 arithmetic
 * ((u32)obj + list->offset), the non-empty case is an else arm rather than an
 * early return, and the list pointer is NOT volatile.  The earlier 4-byte
 * residue (docs/notes/dlist_ops.c.txt) came from the pointer-typed add plus
 * the volatile; with the u32 add the middle is exact under both compilers and
 * the remaining count-load hoist is a 1.1p1 artefact: it closes under
 * ../2.0/sp2 (also sp1, sp2p2..sp2p4), DIFF 8 bytes under 1.1p1.
 * func_02060480 is the list's SetFirstObject step.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020604AC.c \
 *       --func func_020604AC --addr 0x020604AC --arm --cc ../2.0/sp2
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { void *prevObject; void *nextObject; } NNSFndLink;
typedef struct { void *headObject; void *tailObject; u16 numObjects; u16 offset; } NNSFndList;
#define GetLink(list, obj) ((NNSFndLink *)(((u32)(obj)) + (list)->offset))
extern void func_02060480(NNSFndList *list, void *object);
void func_020604AC(NNSFndList *list, void *object)
{
    if (list->headObject == 0)
    {
        func_02060480(list, object);
    }
    else
    {
        NNSFndLink *link = GetLink(list, object);
        link->prevObject = list->tailObject;
        link->nextObject = 0;
        GetLink(list, list->tailObject)->nextObject = object;
        list->tailObject = object;
        list->numObjects++;
    }
}
