/*
 * function: NNSi_SndPlayerInsertSeqPlayer
 * address:  0x02073548
 * packet:   pkt_02073548
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_FndGetNextListObject  0x02060614  arm
 *   NNS_FndInsertListObject  0x02060550  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Obj_02073548 {
    char pad4[4];
    void *f4;
    char pad3d[0x3d - 8];
    u8 b3d;
} Obj_02073548;

struct DList;
extern void *NNS_FndGetNextListObject(struct DList *list, void *elem);
extern void NNS_FndInsertListObject(volatile struct DList *list, void *before, void *elem);

void NNSi_SndPlayerInsertSeqPlayer(void *list, Obj_02073548 *obj)
{
    Obj_02073548 *curr = (Obj_02073548 *)NNS_FndGetNextListObject(list, 0);
    while (curr != 0) {
        if (obj->b3d < curr->b3d) {
            break;
        }
        curr = (Obj_02073548 *)NNS_FndGetNextListObject(list, curr);
    }
    NNS_FndInsertListObject(list, curr, obj);
    obj->f4 = list;
}
