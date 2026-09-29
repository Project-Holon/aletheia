/* NHTTPi_BufFull (nhttp_thread.o): near miss, ~10 attempts. Residue: one instruction. Original has a `b` to the next
 * instruction (+0x78) before the shared `moveq r4,#1`; draft (goto-shared tail) lacks it and is 4 bytes short. */
typedef struct {
    char pad0[4];
    int pos;
    char pad1[0x1c - 8];
    int a1c;
    char pad2[0x28 - 0x20];
    int a28;
} Res;

extern int func_021BB2FC(Res *res_p, int pos);
extern void *func_021BEBF0(void *mutexInfo_p, Res *res_p);
extern void func_021BED04(void *mutexInfo_p, void *connection_p);

int func_021BC2FC(void *mutexInfo_p, Res *res_p)
{
    void *connection_p;
    int full;
    int ret;

    ret = 0;
    full = func_021BB2FC(res_p, res_p->pos);
    if (res_p->a1c != 0 && res_p->a28 != 0) {
        if (full == 0) {
            goto set;
        }
    }
    connection_p = func_021BEBF0(mutexInfo_p, res_p);
    if (connection_p == 0) {
        goto end;
    }
    func_021BED04(mutexInfo_p, connection_p);
    if (res_p->a28 == 0 || res_p->a1c == 0) {
        goto end;
    }
    full = func_021BB2FC(res_p, res_p->pos);
set:
    if (full == 0) {
        ret = 1;
    }
end:
    return ret;
}
