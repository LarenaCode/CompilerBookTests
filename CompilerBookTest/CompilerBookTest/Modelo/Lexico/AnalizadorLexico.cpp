#include "AnalizadorLexico.h"
#include "Token.h"
#include "../TablaSimbolosInizializador.h"


AnalizadorLexico::AnalizadorLexico()
{
}


AnalizadorLexico::~AnalizadorLexico()
{
}

void AnalizadorLexico::insertReserverdWords(TablaSimbolosInizializador* t) {
	t->insertReservedWord("alignas", Enumerados::Token::ALIGNAS);
	t->insertReservedWord("alignof", Enumerados::Token::ALIGNOF);
	t->insertReservedWord("and", Enumerados::Token::AND);
	t->insertReservedWord("and_eq", Enumerados::Token::AND_EQ);
	t->insertReservedWord("asm", Enumerados::Token::ASM);
	t->insertReservedWord("atomic_cancel", Enumerados::Token::ATOMIC_CANCEL);
	t->insertReservedWord("atomic_commit", Enumerados::Token::ATOMIC_COMMIT);
	t->insertReservedWord("atomic_noexcept", Enumerados::Token::ATOMIC_NOEXCEPT);
	t->insertReservedWord("auto", Enumerados::Token::AUTO);
	t->insertReservedWord("bitand", Enumerados::Token::BITAND);
	t->insertReservedWord("and_eq", Enumerados::Token::AND_EQ);
	t->insertReservedWord("bitor", Enumerados::Token::BITOR);
	t->insertReservedWord("bool", Enumerados::Token::BOOL);
	t->insertReservedWord("break", Enumerados::Token::BREAK);
	t->insertReservedWord("case", Enumerados::Token::CASE);
	t->insertReservedWord("catch", Enumerados::Token::CATCH);
	t->insertReservedWord("char8_t", Enumerados::Token::CHAR8_T);
	t->insertReservedWord("char16_t", Enumerados::Token::CHAR16_T);
	t->insertReservedWord("char32_t", Enumerados::Token::CHAR32_T);
	t->insertReservedWord("class", Enumerados::Token::CLASS);
	t->insertReservedWord("compl", Enumerados::Token::COMPL);
	t->insertReservedWord("concept", Enumerados::Token::CONCEPT);
	t->insertReservedWord("const", Enumerados::Token::CONST);
	t->insertReservedWord("consteval", Enumerados::Token::CONSTEVAL);
	t->insertReservedWord("constexpr", Enumerados::Token::CONSTEXPR);
	t->insertReservedWord("const_cast", Enumerados::Token::CONST_CAST);
	t->insertReservedWord("continue", Enumerados::Token::CONTINUE);
	t->insertReservedWord("co_await", Enumerados::Token::CO_AWAIT);
	t->insertReservedWord("co_return", Enumerados::Token::CO_RETURN);
	t->insertReservedWord("co_yield", Enumerados::Token::CO_YIELD);
	t->insertReservedWord("decltype", Enumerados::Token::DECLTYPE);
	t->insertReservedWord("default", Enumerados::Token::DEFAULT);
	t->insertReservedWord("delete", Enumerados::Token::DELETE);
	t->insertReservedWord("export", Enumerados::Token::EXPORT);
	t->insertReservedWord("extern", Enumerados::Token::EXTERN);
	t->insertReservedWord("false", Enumerados::Token::FALSE);
	t->insertReservedWord("float", Enumerados::Token::FLOAT);
	t->insertReservedWord("for", Enumerados::Token::FOR);
	t->insertReservedWord("friend", Enumerados::Token::FRIEND);
	t->insertReservedWord("goto", Enumerados::Token::GOTO);
	t->insertReservedWord("if", Enumerados::Token::IF);
	t->insertReservedWord("inline", Enumerados::Token::INLINE);
	t->insertReservedWord("int", Enumerados::Token::INT);
	t->insertReservedWord("long", Enumerados::Token::LONG);
	t->insertReservedWord("mutable", Enumerados::Token::MUTABLE);
	t->insertReservedWord("namespace", Enumerados::Token::NAMESPACE);
	t->insertReservedWord("new", Enumerados::Token::NEW);
	t->insertReservedWord("noexcept", Enumerados::Token::NOEXCEPT);
	t->insertReservedWord("not", Enumerados::Token::NOT);
	t->insertReservedWord("not_eq", Enumerados::Token::NOT_EQ);
	t->insertReservedWord("private", Enumerados::Token::PRIVATE);
	t->insertReservedWord("protected", Enumerados::Token::PROTECTED);
	t->insertReservedWord("public", Enumerados::Token::PUBLIC);
	t->insertReservedWord("reflexpr", Enumerados::Token::REFLEXPR);
	t->insertReservedWord("register", Enumerados::Token::REGISTER);
	t->insertReservedWord("reinterpret_cast", Enumerados::Token::REINTERPRET_CAST);
	t->insertReservedWord("requires", Enumerados::Token::REQUIRES);
	t->insertReservedWord("return", Enumerados::Token::RETURN);
	t->insertReservedWord("short", Enumerados::Token::SHORT);
	t->insertReservedWord("signed", Enumerados::Token::SIGNED);
	t->insertReservedWord("sizeof", Enumerados::Token::SIZEOF);
	t->insertReservedWord("static", Enumerados::Token::STATIC);
	t->insertReservedWord("static_assert", Enumerados::Token::STATIC_ASSERT);
	t->insertReservedWord("static_cast", Enumerados::Token::STATIC_CAST);
	t->insertReservedWord("struct", Enumerados::Token::STRUCT);
	t->insertReservedWord("switch", Enumerados::Token::SWITCH);
	t->insertReservedWord("synchronized", Enumerados::Token::SYNCHRONIZED);
	t->insertReservedWord("template", Enumerados::Token::TEMPLATE);
	t->insertReservedWord("this", Enumerados::Token::THIS);
	t->insertReservedWord("thread_local", Enumerados::Token::THREAD_LOCAL);
	t->insertReservedWord("throw", Enumerados::Token::THROW);
	t->insertReservedWord("true", Enumerados::Token::TRUE);
	t->insertReservedWord("try", Enumerados::Token::TRY);
	t->insertReservedWord("typedef", Enumerados::Token::TYPEDEF);
	t->insertReservedWord("typeid", Enumerados::Token::TYPEID);
	t->insertReservedWord("typename", Enumerados::Token::TYPENAME);
	t->insertReservedWord("union", Enumerados::Token::UNION);
	t->insertReservedWord("unsigned", Enumerados::Token::UNSIGNED);
	t->insertReservedWord("using", Enumerados::Token::USING);
	t->insertReservedWord("virtual", Enumerados::Token::VIRTUAL);
	t->insertReservedWord("void", Enumerados::Token::VOID);
	t->insertReservedWord("volatile", Enumerados::Token::VOLATILE);
	t->insertReservedWord("wchar_t", Enumerados::Token::WCHAR_T);
	t->insertReservedWord("while", Enumerados::Token::WHILE);
	t->insertReservedWord("xor", Enumerados::Token::XOR);
	t->insertReservedWord("xor_eq", Enumerados::Token::XOR_EQ);
}

Enumerados::Token AnalizadorLexico::getNextToken() {
	return Enumerados::Token::ID;
}