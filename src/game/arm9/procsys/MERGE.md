# procsys (arm9)

Translation unit 0203129C..020316C8, 19 functions. Three parts, all EXACT:

- procsys_p01.c: 0203129C..020313A0 (func_02031348 now takes its four arguments, one prototype of func_020314F4)
- procsys_p02.c: 020313EC..020314F4
- procsys_p03.c: 02031538..020315F0

Open: p02 and p03 do not merge. procsys_p02.c is a generated-looking function (func_020313A0 style casts through struct Obj00371/Obj03005) and func_02031538 returns struct Obj02031538 * where p01 used int; needs a struct pass, not a cast.
