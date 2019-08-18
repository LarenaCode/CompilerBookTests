#pragma once

namespace Enumerados {
	enum class Token {
		ALIGNAS = 256, ALIGNOF = 257, AND = 258, AND_EQ = 259, ASM = 260,
		ATOMIC_CANCEL = 261, ATOMIC_COMMIT = 262, ATOMIC_NOEXCEPT = 267,
		AUTO = 268, BITAND = 269, BITOR = 270, BOOL = 271, BREAK = 272,
		CASE = 273, CATCH = 274, CHAR8_T = 275, CHAR16_T = 276, CHAR32_T = 277,
		CLASS = 278, COMPL = 279, CONCEPT = 280, CONST = 281, CONSTEVAL = 282,
		CONSTEXPR = 283, CONST_CAST = 284, CONTINUE = 285, CO_AWAIT = 286,
		CO_RETURN = 287, CO_YIELD = 288, DECLTYPE = 289, DEFAULT = 290, DELETE = 291,
		DO = 292, DOUBLE = 293, DYNAMIC_CAST = 294, ELSE = 295, ENUM = 296, EXPLICIT = 297,
		EXPORT = 298, EXTERN = 299, FALSE = 300, FLOAT = 301, FOR = 302, FRIEND = 303,
		GOTO = 304, IF = 305, INLINE = 306, INT = 307, LONG = 308, MUTABLE = 309, NAMESPACE = 310,
		NEW = 311, NOEXCEPT = 312, NOT = 313, NOT_EQ = 314, PRIVATE = 315, PROTECTED = 316,
		PUBLIC = 317, REFLEXPR = 318, REGISTER = 319, REINTERPRET_CAST = 320,
		REQUIRES = 321, RETURN = 322, SHORT = 323, SIGNED = 324, SIZEOF = 325, STATIC = 3226,
		STATIC_ASSERT = 237, STATIC_CAST = 328, STRUCT = 329, SWITCH = 330, 
		SYNCHRONIZED = 331, TEMPLATE = 332, THIS = 333, THREAD_LOCAL = 334, THROW = 335,
		TRUE = 336, TRY = 337, TYPEDEF = 338, TYPEID = 339, TYPENAME = 340, UNION = 341,
		UNSIGNED = 342, USING = 343, VIRTUAL = 344, VOID = 345, VOLATILE = 346, WCHAR_T = 347,
		WHILE = 348, XOR = 349, XOR_EQ = 350,
		
		
		
		
		ID = 500,
		

	};
}

/*class Token
{
public:
	
	static Token createToken(std::string nombre);
	static void inicialize();
	~Token();
	std::string getNombre();
	int getCodigo();
	bool agregarValor(std::string valor, TablaEstados tablaEstados);

private:
	Token(std::string nombre, int codigo);
	std::string _nombre;
	int _codigo;
	static int _count;
};*/
