; ModuleID = '.\tmp\struct_inline\test.cpp'
source_filename = ".\5Ctmp\5Cstruct_inline\5Ctest.cpp"
target datalayout = "e-m:w-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.16.27032"

%struct.foo = type { i32, i32, i16, [7 x i16] }

@"?gpAwk@@3PECUfoo@@EC" = dso_local global %struct.foo* null, align 8, !dbg !0

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @"?doSomeMath@@YAHUfoo@@H@Z"(%struct.foo*, i32) #0 !dbg !28 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %1, i32* %3, align 4
  call void @llvm.dbg.declare(metadata i32* %3, metadata !32, metadata !DIExpression()), !dbg !33
  call void @llvm.dbg.declare(metadata %struct.foo* %0, metadata !34, metadata !DIExpression()), !dbg !33
  call void @llvm.dbg.declare(metadata i32* %4, metadata !35, metadata !DIExpression()), !dbg !36
  %5 = getelementptr inbounds %struct.foo, %struct.foo* %0, i32 0, i32 0, !dbg !36
  %6 = load i32, i32* %5, align 4, !dbg !36
  %7 = getelementptr inbounds %struct.foo, %struct.foo* %0, i32 0, i32 1, !dbg !36
  %8 = load i32, i32* %7, align 4, !dbg !36
  %9 = add nsw i32 %6, %8, !dbg !36
  %10 = getelementptr inbounds %struct.foo, %struct.foo* %0, i32 0, i32 3, !dbg !36
  %11 = load i32, i32* %3, align 4, !dbg !36
  %12 = add nsw i32 %11, 1, !dbg !36
  %13 = sext i32 %12 to i64, !dbg !36
  %14 = getelementptr inbounds [7 x i16], [7 x i16]* %10, i64 0, i64 %13, !dbg !36
  %15 = load i16, i16* %14, align 2, !dbg !36
  %16 = sext i16 %15 to i32, !dbg !36
  %17 = add nsw i32 %9, %16, !dbg !36
  %18 = getelementptr inbounds %struct.foo, %struct.foo* %0, i32 0, i32 3, !dbg !36
  %19 = load i32, i32* %3, align 4, !dbg !36
  %20 = add nsw i32 %19, 4, !dbg !36
  %21 = sext i32 %20 to i64, !dbg !36
  %22 = getelementptr inbounds [7 x i16], [7 x i16]* %18, i64 0, i64 %21, !dbg !36
  %23 = load i16, i16* %22, align 2, !dbg !36
  %24 = sext i16 %23 to i32, !dbg !36
  %25 = add nsw i32 %17, %24, !dbg !36
  store i32 %25, i32* %4, align 4, !dbg !36
  %26 = load i32, i32* %4, align 4, !dbg !37
  ret i32 %26, !dbg !37
}

; Function Attrs: nounwind readnone speculatable
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: noinline norecurse nounwind optnone uwtable
define dso_local i32 @main(i32, i8**) #2 !dbg !38 {
  %3 = alloca i32, align 4
  %4 = alloca i8**, align 8
  %5 = alloca i32, align 4
  %6 = alloca %struct.foo, align 4
  %7 = alloca i32, align 4
  %8 = alloca %struct.foo, align 4
  store i32 0, i32* %3, align 4
  store i8** %1, i8*** %4, align 8
  call void @llvm.dbg.declare(metadata i8*** %4, metadata !45, metadata !DIExpression()), !dbg !46
  store i32 %0, i32* %5, align 4
  call void @llvm.dbg.declare(metadata i32* %5, metadata !47, metadata !DIExpression()), !dbg !46
  %9 = load i32, i32* %5, align 4, !dbg !48
  %10 = sub nsw i32 %9, 1, !dbg !48
  store i32 %10, i32* %5, align 4, !dbg !48
  call void @llvm.dbg.declare(metadata %struct.foo* %6, metadata !49, metadata !DIExpression()), !dbg !50
  call void @llvm.dbg.declare(metadata i32* %7, metadata !51, metadata !DIExpression()), !dbg !52
  %11 = load i32, i32* %5, align 4, !dbg !52
  %12 = bitcast %struct.foo* %8 to i8*, !dbg !52
  %13 = bitcast %struct.foo* %6 to i8*, !dbg !52
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 4 %12, i8* align 4 %13, i64 24, i1 false), !dbg !52
  %14 = call i32 @"?doSomeMath@@YAHUfoo@@H@Z"(%struct.foo* %8, i32 %11), !dbg !52
  store i32 %14, i32* %7, align 4, !dbg !52
  %15 = load i32, i32* %7, align 4, !dbg !53
  %16 = getelementptr inbounds %struct.foo, %struct.foo* %6, i32 0, i32 0, !dbg !53
  %17 = load i32, i32* %16, align 4, !dbg !53
  %18 = add nsw i32 %15, %17, !dbg !53
  %19 = getelementptr inbounds %struct.foo, %struct.foo* %6, i32 0, i32 1, !dbg !53
  %20 = load i32, i32* %19, align 4, !dbg !53
  %21 = add nsw i32 %18, %20, !dbg !53
  %22 = getelementptr inbounds %struct.foo, %struct.foo* %6, i32 0, i32 2, !dbg !53
  %23 = load i16, i16* %22, align 4, !dbg !53
  %24 = sext i16 %23 to i32, !dbg !53
  %25 = add nsw i32 %21, %24, !dbg !53
  %26 = getelementptr inbounds %struct.foo, %struct.foo* %6, i32 0, i32 3, !dbg !53
  %27 = getelementptr inbounds [7 x i16], [7 x i16]* %26, i64 0, i64 1, !dbg !53
  %28 = load i16, i16* %27, align 2, !dbg !53
  %29 = sext i16 %28 to i32, !dbg !53
  %30 = add nsw i32 %25, %29, !dbg !53
  %31 = getelementptr inbounds %struct.foo, %struct.foo* %6, i32 0, i32 3, !dbg !53
  %32 = getelementptr inbounds [7 x i16], [7 x i16]* %31, i64 0, i64 6, !dbg !53
  %33 = load i16, i16* %32, align 2, !dbg !53
  %34 = sext i16 %33 to i32, !dbg !53
  %35 = add nsw i32 %30, %34, !dbg !53
  ret i32 %35, !dbg !53
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #3

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone speculatable }
attributes #2 = { noinline norecurse nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="false" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { argmemonly nounwind }

!llvm.dbg.cu = !{!2}
!llvm.module.flags = !{!23, !24, !25, !26}
!llvm.ident = !{!27}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(name: "gpAwk", linkageName: "?gpAwk@@3PECUfoo@@EC", scope: !2, file: !3, line: 9, type: !6, isLocal: false, isDefinition: true)
!2 = distinct !DICompileUnit(language: DW_LANG_C_plus_plus, file: !3, producer: "clang version 8.0.1 (tags/RELEASE_801/final)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !4, globals: !5, nameTableKind: None)
!3 = !DIFile(filename: ".\5Ctmp\5Cstruct_inline\5Ctest.cpp", directory: "F:\5Cdexter\5Cdexter", checksumkind: CSK_MD5, checksum: "5f698900df4bdf90d94d39454fd9b9b1")
!4 = !{}
!5 = !{!0}
!6 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !7, size: 64)
!7 = !DIDerivedType(tag: DW_TAG_volatile_type, baseType: !8)
!8 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "foo", file: !3, line: 1, size: 192, flags: DIFlagTypePassByValue | DIFlagTrivial, elements: !9, identifier: ".?AUfoo@@")
!9 = !{!10, !14, !16, !17, !19}
!10 = !DIDerivedType(tag: DW_TAG_member, name: "size", scope: !8, file: !3, line: 2, baseType: !11, flags: DIFlagStaticMember, extraData: i64 7)
!11 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !12)
!12 = !DIDerivedType(tag: DW_TAG_typedef, name: "size_t", file: !3, line: 9, baseType: !13)
!13 = !DIBasicType(name: "long long unsigned int", size: 64, encoding: DW_ATE_unsigned)
!14 = !DIDerivedType(tag: DW_TAG_member, name: "a", scope: !8, file: !3, line: 3, baseType: !15, size: 32)
!15 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!16 = !DIDerivedType(tag: DW_TAG_member, name: "b", scope: !8, file: !3, line: 4, baseType: !15, size: 32, offset: 32)
!17 = !DIDerivedType(tag: DW_TAG_member, name: "c", scope: !8, file: !3, line: 5, baseType: !18, size: 16, offset: 64)
!18 = !DIBasicType(name: "short", size: 16, encoding: DW_ATE_signed)
!19 = !DIDerivedType(tag: DW_TAG_member, name: "data", scope: !8, file: !3, line: 6, baseType: !20, size: 112, offset: 80)
!20 = !DICompositeType(tag: DW_TAG_array_type, baseType: !18, size: 112, elements: !21)
!21 = !{!22}
!22 = !DISubrange(count: 7)
!23 = !{i32 2, !"CodeView", i32 1}
!24 = !{i32 2, !"Debug Info Version", i32 3}
!25 = !{i32 1, !"wchar_size", i32 2}
!26 = !{i32 7, !"PIC Level", i32 2}
!27 = !{!"clang version 8.0.1 (tags/RELEASE_801/final)"}
!28 = distinct !DISubprogram(name: "doSomeMath", linkageName: "?doSomeMath@@YAHUfoo@@H@Z", scope: !3, file: !3, line: 23, type: !29, scopeLine: 23, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !2, retainedNodes: !4)
!29 = !DISubroutineType(types: !30)
!30 = !{!15, !8, !31}
!31 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !15)
!32 = !DILocalVariable(name: "arg", arg: 2, scope: !28, file: !3, line: 23, type: !31)
!33 = !DILocation(line: 23, scope: !28)
!34 = !DILocalVariable(name: "bar", arg: 1, scope: !28, file: !3, line: 23, type: !8)
!35 = !DILocalVariable(name: "someMath", scope: !28, file: !3, line: 24, type: !15)
!36 = !DILocation(line: 24, scope: !28)
!37 = !DILocation(line: 26, scope: !28)
!38 = distinct !DISubprogram(name: "main", scope: !3, file: !3, line: 37, type: !39, scopeLine: 37, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !2, retainedNodes: !4)
!39 = !DISubroutineType(types: !40)
!40 = !{!15, !15, !41}
!41 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !42, size: 64)
!42 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !43, size: 64)
!43 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !44)
!44 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!45 = !DILocalVariable(name: "argv", arg: 2, scope: !38, file: !3, line: 37, type: !41)
!46 = !DILocation(line: 37, scope: !38)
!47 = !DILocalVariable(name: "argc", arg: 1, scope: !38, file: !3, line: 37, type: !15)
!48 = !DILocation(line: 38, scope: !38)
!49 = !DILocalVariable(name: "bar", scope: !38, file: !3, line: 39, type: !8)
!50 = !DILocation(line: 39, scope: !38)
!51 = !DILocalVariable(name: "mainThing", scope: !38, file: !3, line: 43, type: !15)
!52 = !DILocation(line: 43, scope: !38)
!53 = !DILocation(line: 45, scope: !38)
