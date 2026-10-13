/*
 * file:     unit_021D3568.c
 * unit:     yes
 * function: func_021D3568, func_021D35C8, func_021D3630, func_021D3688, func_021D36CC, func_021D36EC, func_021D370C, func_021D3734, func_021D375C, func_021D377C, func_021D3794, func_021D37B8, func_021D37DC, func_021D37FC, func_021D381C, func_021D3894, func_021D38AC, func_021D38C4, func_021D38E0, func_021D3900, func_021D3918, func_021D3934, func_021D3988, func_021D39A8
 * address:  0x021D3568
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689C9F8  0x0689C9F8  thumb
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021EA3E8  0x021EA3E8  thumb  ov093
 *   func_021EA3F8  0x021EA3F8  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D66D8  0x021D66D8  thumb  ov093
 *   func_021EA888  0x021EA888  thumb  ov093
 *   func_021EA8A4  0x021EA8A4  thumb  ov093
 *   func_021EA768  0x021EA768  thumb  ov093
 *   func_021EA778  0x021EA778  thumb  ov093
 *   func_021EA788  0x021EA788  thumb  ov093
 *   func_021EA798  0x021EA798  thumb  ov093
 *   func_021D5F90 0x021D5F90 thumb ov093
 *   func_021D5FA4 0x021D5FA4 thumb ov093
 *   func_021D5608 0x021D5608 thumb ov093
 *   func_021D5640 0x021D5640 thumb ov093
 *   func_021D56CC 0x021D56CC thumb ov093
 *   func_021D5FB8   0x021D5FB8  thumb
 *   func_021D5674 0x021D5674 thumb ov093
 *   func_021D56A0 0x021D56A0 thumb ov093
 *   func_021D5DC0 0x021D5DC0 thumb ov093
 *   func_021D5E38 0x021D5E38 thumb ov093
 *   func_021D5EA8  0x021D5EA8  thumb  ov093
 *   func_021D5EFC   0x021D5EFC  thumb
 *   func_021D5F08   0x021D5F08  thumb
 *   func_021D5F38 0x021D5F38 thumb ov093
 *   func_021D6034 0x021D6034 thumb ov093
 *   func_021D61F0   0x021D61F0  thumb
 *   func_021D6238 0x021D6238 thumb ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   func_021D63EC  0x021D63EC  thumb  ov093
 *   func_021D6580  0x021D6580  thumb  ov093
 *   func_021D66B0 0x021D66B0 thumb ov093
 *   func_021D8090  0x021D8090  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D6064  0x021D6064  thumb  ov093
 */
#include "unit_021D3568_types.h"

/*
 * Server command handlers of the battle client (module BTL_CLIENT): each
 * one is a row of the client command table, whose second column is the
 * command id (given per handler below). The first part drives the battle
 * view; the second part applies a state change to one Pokemon.
 */

extern u32 func_021CD9E0(struct BtlClient *client);
extern u8 func_021B8E70(struct BtlMain *main, u32 position);
extern void func_021EA3E8(struct BtlvCore *view, int viewPosA, int viewPosB, u32 param);
extern int func_021EA3F8(struct BtlvCore *view);
extern int func_021B8D8C(struct BtlMain *main, struct BtlPokeContainer *container, u32 pokeId);
extern struct BtlPokeParam *func_021B9934(struct BtlPokeContainer *container, int pokeId);
extern void func_021D66D8(struct BtlPokeParam *pokeParam, u8 form);
extern void func_021EA888(struct BtlvCore *view, int viewPos);
extern int func_021EA8A4(struct BtlvCore *view);
extern void func_021EA768(struct BtlvCore *view, u32 position, u32 flag);
extern int func_021EA778(struct BtlvCore *view, u32 position);
extern void func_021EA788(struct BtlvCore *view, u32 position);
extern int func_021EA798(struct BtlvCore *view, u32 position);
extern void func_021D5F90(struct BtlPokeParam *pokeParam, u16 damage);
extern void func_021D5FA4(struct BtlPokeParam *pokeParam, u16 amount);
extern void func_021D5608(struct BtlPokeParam *pokeParam, u8 slot, u8 amount);
extern void func_021D5640(struct BtlPokeParam *pokeParam, u32 slot, u32 amount);
extern void func_021D56CC(struct BtlPokeParam *pokeParam, u8 slot);
extern void func_021D5FB8(struct BtlPokeParam *pokeParam);
extern u16 func_021D5674(struct BtlPokeParam *pokeParam, u32 slot, u8 amount);
extern u16 func_021D56A0(struct BtlPokeParam *pokeParam, u32 slot, u8 amount);
extern u8 func_021D5DC0(struct BtlPokeParam *pokeParam, int statIndex, u8 steps);
extern u8 func_021D5E38(struct BtlPokeParam *pokeParam, int statIndex, u8 steps);
extern void func_021D5EA8(struct BtlPokeParam *pokeParam, int statIndex, u8 stage);
extern int func_021D5EFC(struct BtlPokeParam *pokeParam);
extern void func_021D5F08(struct BtlPokeParam *pokeParam);
extern int func_021D5F38(struct BtlPokeParam *pokeParam, int delta);
extern void func_021D6034(struct BtlPokeParam *pokeParam, int sickIndex, union SickCont cont);
extern void func_021D61F0(struct BtlPokeParam *pokeParam);
extern void func_021D6238(struct BtlPokeParam *pokeParam, int sickIndex);
extern void *func_021B9AEC(struct BtlPokeContainer *container, int clientId);
extern void func_021B9C10(void *party, int indexA, int indexB);
extern struct BtlPokeParam *func_021B9BF0(void *party, u32 index);
extern void func_021D63EC(struct BtlPokeParam *pokeParam, u16 threshold);
extern void func_021D6580(struct BtlPokeParam *pokeParam);
extern void func_021D66B0(struct BtlPokeParam *pokeParam, int species);
extern void func_021D8090(u32 packed, u8 *out);
extern u32 func_0689C9F8(u32 index);
extern int func_021D5B68(struct BtlPokeParam *pokeParam);
extern int func_021D6064(struct BtlPokeParam *pokeParam, u32 sickIndex, union SickCont *outCont, int *outCured);

int func_021D3568(struct BtlClient *client, int *seq, u32 *args);
int func_021D35C8(struct BtlClient *client, int *seq, u32 *args);
int func_021D3630(struct BtlClient *client, int *seq, u32 *args);
int func_021D3688(struct BtlClient *client, int *seq, u32 *args);
int func_021D36CC(struct BtlClient *client, int *seq, u32 *args);
int func_021D36EC(struct BtlClient *client, int *seq, u32 *args);
int func_021D370C(struct BtlClient *client, int *seq, u32 *args);
int func_021D3734(struct BtlClient *client, int *seq, u32 *args);
int func_021D375C(struct BtlClient *client, int *seq, u32 *args);
int func_021D377C(struct BtlClient *client, int *seq, u32 *args);
int func_021D3794(struct BtlClient *client, int *seq, u32 *args);
int func_021D37B8(struct BtlClient *client, int *seq, u32 *args);
int func_021D37DC(struct BtlClient *client, int *seq, u32 *args);
int func_021D37FC(struct BtlClient *client, int *seq, u32 *args);
int func_021D381C(struct BtlClient *client, int *seq, u32 *args);
int func_021D3894(struct BtlClient *client, int *seq, u32 *args);
int func_021D38AC(struct BtlClient *client, int *seq, u32 *args);
int func_021D38C4(struct BtlClient *client, int *seq, u32 *args);
int func_021D38E0(struct BtlClient *client, int *seq, u32 *args);
int func_021D3900(struct BtlClient *client, int *seq, u32 *args);
int func_021D3918(struct BtlClient *client, int *seq, u32 *args);
int func_021D3934(struct BtlClient *client, int *seq, u32 *args);
int func_021D3988(struct BtlClient *client, int *seq, u32 *args);
int func_021D39A8(struct BtlClient *client, int *seq, u32 *args);


/* Command 0x4F. Two battle positions swap places in the view; args: positionA, positionB, animation. */
int func_021D3568(struct BtlClient *client, int *seq, u32 *args)
{
    int viewPosA;
    int viewPosB;

    if (*seq == 0) {
        if (func_021CD9E0(client) != 0) {
            return 1;
        }
        viewPosA = func_021B8E70(client->main, (u8)args[0]);
        viewPosB = func_021B8E70(client->main, (u8)args[1]);
        func_021EA3E8(client->view, viewPosA, viewPosB, (u16)args[2]);
        (*seq)++;
    } else {
        if (func_021EA3F8(client->view) != 0) {
            return 1;
        }
    }
    return 0;
}


/* Command 0x50. A Pokemon changes form; args: pokeId, form. */
int func_021D35C8(struct BtlClient *client, int *seq, u32 *args)
{
    int viewPos;

    switch (*seq) {
    case 0:
        viewPos = func_021B8E70(client->main, func_021B8D8C(client->main, client->pokeContainer, (u8)args[0]));
        func_021D66D8(func_021B9934(client->pokeContainer, (u8)args[0]), (u8)args[1]);
        func_021EA888(client->view, viewPos);
        (*seq)++;
        break;
    case 1:
        if (func_021EA8A4(client->view) != 0) {
            (*seq)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}


/* Command 0x58. Show the status panel of a Pokemon; args: pokeId. */
int func_021D3630(struct BtlClient *client, int *seq, u32 *args)
{
    int position;

    position = func_021B8D8C(client->main, client->pokeContainer, (u8)args[0]);
    switch (*seq) {
    case 0:
        if (func_021CD9E0(client) != 0) {
            return 1;
        }
        func_021EA768(client->view, position, 1);
        (*seq)++;
        break;
    case 1:
        if (func_021EA778(client->view, position) != 0) {
            (*seq)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}


/* Command 0x01. Hide the status panel of a Pokemon; args: pokeId. */
int func_021D3688(struct BtlClient *client, int *seq, u32 *args)
{
    int position;

    position = func_021B8D8C(client->main, client->pokeContainer, (u8)args[0]);
    switch (*seq) {
    case 0:
        func_021EA788(client->view, position);
        (*seq)++;
        break;
    case 1:
        if (func_021EA798(client->view, position) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * Command 0x02. Subtract HP; args: pokeId, damage.
 * extent: compiled 30 bytes followed by two zero alignment bytes.
 */
int func_021D36CC(struct BtlClient *client, int *seq, u32 *args)
{
    func_021D5F90(func_021B9934(client->pokeContainer, (u8)args[0]), args[1]);
    return 1;
}

/* Command 0x03. Add HP up to the maximum; args: pokeId, amount. */
int func_021D36EC(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = func_021B9934(client->pokeContainer, (u8)args[0]);
    func_021D5FA4(pokeParam, args[1]);
    return 1;
}

/* Command 0x05. Subtract PP of a move in both the original and the working copy; args: pokeId, moveSlot, amount. */
int func_021D370C(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    u8 moveSlot, amount;
    moveSlot = args[1];
    amount = args[2];
    pokeParam = func_021B9934(client->pokeContainer, (u8)args[0]);
    func_021D5608(pokeParam, moveSlot, amount);
    return 1;
}

/* Command 0x06. Subtract PP of a move in the working copy only; args: pokeId, moveSlot, amount. */
int func_021D3734(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    u8 moveSlot, amount;
    moveSlot = args[1];
    amount = args[2];
    pokeParam = func_021B9934(client->pokeContainer, (u8)args[0]);
    func_021D5640(pokeParam, moveSlot, amount);
    return 1;
}

/* Command 0x07. Mark a move slot as used; args: pokeId, moveSlot. */
int func_021D375C(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    u8 moveSlot;
    moveSlot = args[1];
    pokeParam = func_021B9934(client->pokeContainer, (u8)args[0]);
    func_021D56CC(pokeParam, moveSlot);
    return 1;
}


/* Command 0x04. Set HP to 0; args: pokeId. */
int func_021D377C(struct BtlClient *client, int *seq, u32 *args)
{
    func_021D5FB8(func_021B9934(client->pokeContainer, (u8)*args));
    return 1;
}

/* Command 0x08. Restore PP of the original move; args: pokeId, moveSlot, amount. */
int func_021D3794(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = func_021B9934(client->pokeContainer, (u8)args[0]);
    func_021D5674(pokeParam, (u8)args[1], args[2]);
    return 1;
}

/* Command 0x09. Restore PP of the working move copy; args: pokeId, moveSlot, amount. */
int func_021D37B8(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = func_021B9934(client->pokeContainer, (u8)args[0]);
    func_021D56A0(pokeParam, (u8)args[1], args[2]);
    return 1;
}

/* Command 0x0A. Raise one stat stage; args: pokeId, statIndex, steps. */
int func_021D37DC(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = func_021B9934(client->pokeContainer, (u8)args[0]);
    func_021D5DC0(pokeParam, args[1], args[2]);
    return 1;
}

/* Command 0x0B. Lower one stat stage; args: pokeId, statIndex, steps. */
int func_021D37FC(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = func_021B9934(client->pokeContainer, (u8)args[0]);
    func_021D5E38(pokeParam, args[1], args[2]);
    return 1;
}


/* Command 0x0C. Set all seven stat stages; args: pokeId, then one stage per stat. */
int func_021D381C(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = func_021B9934(client->pokeContainer, (u8)args[0]);
    func_021D5EA8(pokeParam, 1, args[1]);
    func_021D5EA8(pokeParam, 2, args[2]);
    func_021D5EA8(pokeParam, 3, args[3]);
    func_021D5EA8(pokeParam, 4, args[4]);
    func_021D5EA8(pokeParam, 5, args[5]);
    func_021D5EA8(pokeParam, 6, args[6]);
    func_021D5EA8(pokeParam, 7, args[7]);
    return 1;
}


/* Command 0x0D. Recover lowered stat stages; args: pokeId. */
int func_021D3894(struct BtlClient *client, int *seq, u32 *args)
{
    func_021D5EFC(func_021B9934(client->pokeContainer, (u8)*args));
    return 1;
}


/* Command 0x0E. Reset all stat stages to neutral; args: pokeId. */
int func_021D38AC(struct BtlClient *client, int *seq, u32 *args)
{
    func_021D5F08(func_021B9934(client->pokeContainer, (u8)*args));
    return 1;
}

/* Command 0x0F. Change the critical hit stage; args: pokeId, delta. */
int func_021D38C4(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = func_021B9934(client->pokeContainer, (u8)args[0]);
    func_021D5F38(pokeParam, args[1]);
    return 1;
}

/*
 * Command 0x10. Store a status condition; args: pokeId, sickIndex, condition.
 * lever: A declared one-word local assigned from args[2] preserves all 32
 * bits and emits the otherwise unused frame word. A cast lvalue at
 * args+2 compiled 30 bytes with the wrong frame and redundant address add.
 */
int func_021D38E0(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;
    union SickCont cont;

    pokeParam = func_021B9934(client->pokeContainer, (u8)args[0]);
    cont.raw = args[2];
    func_021D6034(pokeParam, args[1], cont);
    return 1;
}


/* Command 0x11. Clear the major status; args: pokeId. */
int func_021D3900(struct BtlClient *client, int *seq, u32 *args)
{
    func_021D61F0(func_021B9934(client->pokeContainer, (u8)*args));
    return 1;
}

/* Command 0x12. Clear one status condition; args: pokeId, sickIndex. */
int func_021D3918(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = func_021B9934(client->pokeContainer, (u8)args[0]);
    func_021D6238(pokeParam, args[1]);
    return 1;
}


/*
 * Command 0x13. A party member comes into battle: swap the two party
 * entries, reload the incoming Pokemon and arm its turn threshold; args[3]
 * is the threshold. The indices and the client come from the client work.
 */
int func_021D3934(struct BtlClient *client, int *seq, u32 *args)
{
    u8 indexFrom;
    u8 indexTo;
    void *party;
    struct BtlPokeParam *incoming;

    indexFrom = client->swapFrom;
    indexTo = client->swapTo;
    party = func_021B9AEC(client->pokeContainer, (u8)(client->swapClientId));
    if (indexFrom != indexTo)
        func_021B9C10(party, indexFrom, indexTo);
    incoming = func_021B9BF0(party, indexFrom);
    func_021D63EC(incoming, args[3]);
    func_021D6580(incoming);
    return 1;
}

/* Command 0x15. Set the two types of a Pokemon from a species; args: pokeId, species. */
int func_021D3988(struct BtlClient *client, int *seq, u32 *args)
{
    struct BtlPokeParam *pokeParam;

    pokeParam = func_021B9934(client->pokeContainer, (u8)args[0]);
    func_021D66B0(pokeParam, (u16)args[1]);
    return 1;
}


/*
 * Command 0x17. Clear status conditions on several Pokemon; args:
 * pokeCount, sickCount, packed poke ids (six 5-bit values). Each sick index
 * comes from func_0689C9F8; a zero index ends the list.
 */
int func_021D39A8(struct BtlClient *client, int *seq, u32 *args)
{
    u8 pokeIds[6];
    u32 i;
    u32 sickCount;
    u32 pokeCount;
    u32 j;
    u32 sickIndex;
    struct BtlPokeParam *pokeParam;

    sickCount = args[1];
    pokeCount = args[0];
    func_021D8090(args[2], pokeIds);
    for (i = 0; i < sickCount; i++) {
        sickIndex = func_0689C9F8(i);
        if (sickIndex == 0)
            break;
        for (j = 0; j < pokeCount; j++) {
            pokeParam = func_021B9934(client->pokeContainer, pokeIds[j]);
            if (func_021D5B68(pokeParam) == 0)
                func_021D6064(pokeParam, sickIndex, 0, 0);
        }
    }
    return 1;
}
