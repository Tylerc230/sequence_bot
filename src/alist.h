#ifndef ALIST_H_INCLUDED
#define ALIST_H_INCLUDED

#include <stdlib.h>
#include <string.h>

using namespace std;

typedef enum __ItemValueType
{
	IVT_NULL = 0,
	IVT_BOOL = 1,
	IVT_INT = 2,
	IVT_FLOAT = 3,
	IVT_DOUBLE = 4,
	IVT_STRING = 5,
	IVT_LIST = 6,
	IVT_OBJECT = 7

} _ItemValueType;

class _Generic
{
	public:
		_Generic()
		{
		}

		virtual ~_Generic()
		{
		}

	protected:
		virtual void Destroy() = 0;

};

typedef struct __ItemValueInfo
{
	int index;
	char* name;
	_ItemValueType type;
	union
	{
		bool bValue;
		int iValue;
		float fValue;
		double eValue;
		char* sValue;
		_Generic* aValue;
		void* oValue;
	};

} _ItemValueInfo, *_lpItemValueInfo;

class ItemInfo : public _Generic
{
	public:
		ItemInfo()
		{
			memset(&m_value, 0, sizeof(_ItemValueInfo));
			m_value.type = IVT_NULL;
			m_value.index = -1;
		}

		ItemInfo(ItemInfo& ref)
		{
			m_value.type = ref.get_type();
			switch (m_value.type)
			{
				case IVT_BOOL:
					{
						m_value.bValue = ref.get_value().bValue;
					}
					break;

				case IVT_INT:
					{
						m_value.iValue = ref.get_value().iValue;
					}
					break;

				case IVT_FLOAT:
					{
						m_value.fValue = ref.get_value().fValue;
					}
					break;

				case IVT_DOUBLE:
					{
						m_value.eValue = ref.get_value().eValue;
					}
					break;

				case IVT_STRING:
					{
						char* sValue = ref.get_value().sValue;
						int len = strlen(sValue) + 1;
						m_value.sValue = (char*)malloc(len);
						strncpy(m_value.sValue, sValue, len-1);
						m_value.sValue[len-1] = '\0';
					}
					break;

				case IVT_LIST:
					{
						m_value.aValue = ref.get_value().aValue;
					}
					break;

				case IVT_OBJECT:
					{
						m_value.oValue = ref.get_value().oValue;
					}
					break;

				default:
					{
						memset(&m_value, 0, sizeof(_ItemValueInfo));
						m_value.type = IVT_NULL;
					}
					break;
			}
		}

		virtual ~ItemInfo()
		{
			free(m_value.name);

			Destroy();
		}

		inline ItemInfo& operator = (ItemInfo& ref)
		{
			Destroy();

			m_value.type = ref.get_type();
			switch (m_value.type)
			{
				case IVT_BOOL:
					{
						m_value.bValue = ref.get_value().bValue;
					}
					break;

				case IVT_INT:
					{
						m_value.iValue = ref.get_value().iValue;
					}
					break;

				case IVT_FLOAT:
					{
						m_value.fValue = ref.get_value().fValue;
					}
					break;

				case IVT_DOUBLE:
					{
						m_value.eValue = ref.get_value().eValue;
					}
					break;

				case IVT_STRING:
					{
						char* sValue = ref.get_value().sValue;
						int len = strlen(sValue) + 1;
						m_value.sValue = (char*)malloc(len);
						strncpy(m_value.sValue, sValue, len-1);
						m_value.sValue[len-1] = '\0';
					}
					break;

				case IVT_LIST:
					{
						m_value.aValue = ref.get_value().aValue;
					}
					break;

				case IVT_OBJECT:
					{
						m_value.oValue = ref.get_value().oValue;
					}
					break;

				default:
					{
						memset(&m_value, 0, sizeof(_ItemValueInfo));
						m_value.type = IVT_NULL;
					}
					break;
			}

			return (*this);
		}

		inline ItemInfo& operator = (const bool& ref)
		{
			Destroy();

			m_value.type = IVT_BOOL;
			m_value.bValue = ref;

			return (*this);
		}

		inline ItemInfo& operator = (const int& ref)
		{
			Destroy();

			m_value.type = IVT_INT;
			m_value.iValue = ref;

			return (*this);
		}

		inline ItemInfo& operator = (const float& ref)
		{
			Destroy();

			m_value.type = IVT_FLOAT;
			m_value.fValue = ref;

			return (*this);
		}

		inline ItemInfo& operator = (const double& ref)
		{
			Destroy();

			m_value.type = IVT_DOUBLE;
			m_value.eValue = ref;

			return (*this);
		}

		inline ItemInfo& operator = (const char* ref)
		{
			Destroy();

			m_value.type = IVT_STRING;
			int len = strlen(ref) + 1;
			m_value.sValue = (char*)malloc(len);
			strncpy(m_value.sValue, ref, len-1);
			m_value.sValue[len-1] = '\0';

			return (*this);
		}

		inline ItemInfo& operator = (_Generic* ref)
		{
			Destroy();

			m_value.type = IVT_LIST;
			m_value.aValue = ref;

			return (*this);
		}

		inline ItemInfo& operator = (void* ref)
		{
			Destroy();

			m_value.type = IVT_OBJECT;
			m_value.oValue = ref;

			return (*this);
		}


		ItemInfo& operator [] (const int index);
		ItemInfo& operator [] (const char* name);

		inline int get_index()
		{
			return (m_value.index);
		}

		inline void set_index(const int index)
		{
			m_value.index = index;
		}

		inline char* get_name()
		{
			return (m_value.name);
		}

		inline void set_name(const char* name)
		{
			int len = strlen(name) + 1;
			m_value.name = (char*)realloc(m_value.name, len*sizeof(char));
			strcpy(m_value.name, name);
			m_value.name[len-1] = '\0';
		}

		inline _ItemValueType get_type()
		{
			return (m_value.type);
		}

		inline _ItemValueInfo get_value()
		{
			return (m_value);
		}

	protected:
		virtual void Destroy()
		{
			if (m_value.type == IVT_STRING)
			{
				free(m_value.sValue);
			}

			if (m_value.type == IVT_LIST)
			{
				delete (m_value.aValue);
			}

			m_value.type = IVT_NULL;
		}

	private:
		_ItemValueInfo m_value;

};

class AList : public _Generic
{
	public:
		AList()
		{
			m_items = NULL;
			m_size = 0;
		}

		virtual ~AList()
		{
			empty();
		}

		inline void empty()
		{
			Destroy();
		}

		inline ItemInfo& operator[] (const int index)
		{
			ItemInfo* pItem = find_item(index);
			if (pItem != NULL)
			{
				return (*pItem);
			}
			else
			{
				m_size++;
				m_items = (ItemInfo**)realloc(m_items, m_size*sizeof(ItemInfo*));
				m_items[m_size-1] = new ItemInfo();
				m_items[m_size-1]->set_index(index);
				return (*(m_items[m_size-1]));
			}
		}

		inline ItemInfo& operator[] (const char* name)
		{
			ItemInfo* pItem = find_item(name);
			if (pItem != NULL)
			{
				return (*pItem);
			}
			else
			{
				m_size++;
				m_items = (ItemInfo**)realloc(m_items, m_size*sizeof(ItemInfo*));
				m_items[m_size-1] = new ItemInfo();
				m_items[m_size-1]->set_name(name);
				return (*(m_items[m_size-1]));
			}
		}


		inline int get_size()
		{
			return m_size;
		}

		inline ItemInfo** get_items()
		{
			return m_items;
		}

		inline ItemInfo* find_item(const int index)
		{
			int iIndex = -1;
			for (int i=0; i<m_size; i++)
			{
				if (m_items[i]->get_index() == index)
				{
					iIndex = i;
					break;
				}
			}

			if (iIndex != -1)
			{
				return (m_items[iIndex]);
			}
			else
			{
				return NULL;
			}
		}

		inline ItemInfo* find_item(const char* name)
		{
			int iIndex = -1;
			for (int i=0; i<m_size; i++)
			{
				if (strcmp(m_items[i]->get_name(), name) == 0)
				{
					iIndex = i;
					break;
				}
			}

			if (iIndex != -1)
			{
				return (m_items[iIndex]);
			}
			else
			{
				return NULL;
			}
		}

	protected:
		virtual void Destroy()
		{
			for (int i=0; i<m_size; i++)
			{
				delete m_items[i];
			}
			free(m_items);
			m_size = 0;
		}

	private:
		ItemInfo** m_items;
		int m_size;

};

ItemInfo& ItemInfo::operator[] (const int index)
{
	return (((AList&)(*m_value.aValue))[index]);
}

ItemInfo& ItemInfo::operator[] (const char* name)
{
	return (((AList&)(*m_value.aValue))[name]);
}

#endif // ALIST_H_INCLUDED
