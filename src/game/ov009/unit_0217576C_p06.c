/*
 * file:     unit_0217576C_p06.c
 * unit:     yes
 * function: func_0217604C, func_021760FC, func_02176164
 * address:  0x0217604C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 */
struct node_s {
    int w[10];
};

typedef struct NodeRec { int w[10]; } NodeRec;

typedef struct Node { char pad[0x54]; NodeRec rec; } Node;

extern char *func_02175F3C(void);
int func_0217604C(struct node_s *newNode);
int func_021760FC(struct node_s *newNode);
int func_02176164(unsigned char aid);


/*
 * sdk:      DWCi_NodeInfoList_InsertToTop (dwc_match.o)
 */
int func_0217604C(struct node_s *newNode)
{
    int i;

    if (*(int *)(func_02175F3C() + 0x50) == 32)
        return 0;
    for (i = *(int *)(func_02175F3C() + 0x50); i > 0; i--)
        ((struct node_s *)(func_02175F3C() + 0x54))[i] = ((struct node_s *)(func_02175F3C() + 0x54))[i - 1];
    *(struct node_s *)(func_02175F3C() + 0x54) = *newNode;
    *(int *)(func_02175F3C() + 0x50) += 1;
    return 1;
}


/*
 * sdk:      DWCi_NodeInfoList_Append (dwc_match.o)
 */
int func_021760FC(struct node_s *newNode)
{
    if (*(int *)(func_02175F3C() + 0x50) == 32)
        return 0;
    *(struct node_s *)(func_02175F3C() + 0x54 + *(int *)(func_02175F3C() + 0x50) * 40) = *newNode;
    *(int *)(func_02175F3C() + 0x50) += 1;
    return 1;
}


/*
 * sdk:      DWCi_NodeInfoList_RemoveAID (TwlDWC/libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * Removes the node with this AID from the node-info list and shifts the tail
 * down one 0x28-byte record.
 *
 * The shift-down loop reads BOTH list bases first and only then does the index
 * arithmetic: the two func_02175F3C() results go into two raw char* locals, the
 * destination is `a + i * 0x28` (old i), then i is bumped, then the source is
 * `b + i * 0x28` (new i).  That is what makes the image keep the first result
 * raw in r7 across the second call (`mov r7, r0`) and emit both `mla`s after
 * it; folding the arithmetic into the first call site loses those 4 bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_02176164.c \
 *       --func func_02176164 --addr 0x02176164 --region ov009 --arm --lang c99 --cc 1.1p1 --diff
 */
int func_02176164(unsigned char aid)
{
    int removeAidIndex;
    int i;
    Node *d;
    Node *s;

    if (*(int *)(func_02175F3C() + 0x50) == 0) return 0;
    for (removeAidIndex = 0; removeAidIndex < *(int *)(func_02175F3C() + 0x50);
         removeAidIndex++) {
        if (aid == *(unsigned char *)(func_02175F3C() + removeAidIndex * 0x28 + 0x6a))
            break;
    }
    if (removeAidIndex == *(int *)(func_02175F3C() + 0x50)) return 0;
    for (i = removeAidIndex; i < *(int *)(func_02175F3C() + 0x50) - 1; ) {
        char *a = (char *)func_02175F3C();
        char *b = (char *)func_02175F3C();
        d = (Node *)(a + i * 0x28);
        i++;
        s = (Node *)(b + i * 0x28);
        d->rec = s->rec;
    }
    *(int *)(func_02175F3C() + 0x50) -= 1;
    return 1;
}
