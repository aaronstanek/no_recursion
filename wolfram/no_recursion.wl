(* ::Package:: *)

noRecursionStartup[]:=List[<||>]


noRecursionDepth[inp_]:=Length[inp]


noRecursionPush[inp_]:=Append[inp,<||>]


noRecursionPop[inp_]:=Delete[inp,-1]


noRecursionAcSet[inp_,name_,value_]:=Module[{m},
m = inp[[-1]];
m = Append[m,name->value];
Return[ReplacePart[inp,-1->m]];
]


noRecursionAcDel[inp_,name_]:=Module[{m},
m = inp[[-1]];
m = Delete[m,name];
Return[ReplacePart[inp,-1->m]];
]


noRecursionAcGet[inp_,name_]:=Module[{m},
m = inp[[-1]];
Return[m[name]];
]


noRecursionPrevSet[inp_,name_,value_]:=Module[{m},
m = inp[[-2]];
m = Append[m,name->value];
Return[ReplacePart[inp,-2->m]];
]


noRecursionPrevDel[inp_,name_]:=Module[{m},
m = inp[[-2]];
m = Delete[m,name];
Return[ReplacePart[inp,-2->m]];
]


noRecursionPrevGet[inp_,name_]:=Module[{m},
m = inp[[-2]];
Return[m[name]];
]
