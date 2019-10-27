#pragma once
#include "Pokemon.h"
#include "Lista.h"
namespace Lab4DiegoMorales1132119 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Diagnostics;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnMostrar;
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnMostrar = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// btnMostrar
			// 
			this->btnMostrar->Location = System::Drawing::Point(102, 227);
			this->btnMostrar->Name = L"btnMostrar";
			this->btnMostrar->Size = System::Drawing::Size(75, 23);
			this->btnMostrar->TabIndex = 0;
			this->btnMostrar->Text = L"Mostrar";
			this->btnMostrar->UseVisualStyleBackColor = true;
			this->btnMostrar->Click += gcnew System::EventHandler(this, &MyForm::BtnMostrar_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(13, 19);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(259, 199);
			this->listBox1->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->btnMostrar);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
		Lista* MiLista = new Lista();
		Pokemon* MiPokemon = new Pokemon();
	private: System::Void BtnMostrar_Click(System::Object^ sender, System::EventArgs^ e) {
		StreamReader^ streamReader = gcnew StreamReader("C:/Users/Diego/source/repos/Lab4_Diego_Morales_1132119/ListaPokemon.txt");

		String^ textoDelArchivo = streamReader->ReadToEnd();
		String^ palabra; //nombre del pokemon
		String^ numeroReg;
		String^ numeroNac;
		String^ aux;
		
		int pos;
		while (textoDelArchivo != "") //
		{
			pos = textoDelArchivo->IndexOf(",");
			palabra = textoDelArchivo->Substring(0, pos);
			aux = textoDelArchivo;
			textoDelArchivo = aux->Substring(pos + 1);

			pos = textoDelArchivo->IndexOf(",");
			numeroReg = textoDelArchivo->Substring(0, pos);
			aux = textoDelArchivo;
			textoDelArchivo = aux->Substring(pos + 1);

			pos = textoDelArchivo->IndexOf(",");
			numeroNac = textoDelArchivo->Substring(0, pos);
			aux = textoDelArchivo;
			textoDelArchivo = aux->Substring(pos + 1);

			//almacenar en estructura
			//std::string standardString = marshal_as<std::string>(managedString);
			//MiPokemon.Nombre = marshal_as<std::string>(palabra);
			//MiPokemon.GenNumber = int::Parse(numeroReg);
			MiPokemon->NatNumber = int::Parse(numeroNac);
			int Nac = MiPokemon->NatNumber;
			MiLista->Push(Nac);
			
		}
		// desplegar numeros
		MostrarLista();
	}
	public: void MostrarLista()
	{
		int VectorLista[70] = { 11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11 };
		int i = 0;
		Nodo* Aux = new Nodo();
		Aux = MiLista->First;
		listBox1->Items->Clear();
		while (Aux != nullptr && VectorLista[i] == 11)
		{
			VectorLista[i] = Aux->NatNumber.NatNumber;
			i++;
			Aux = Aux->siguiente;
		}
		i = 0;
		while (VectorLista[i] != 11 && i <= 69)
		{
			listBox1->Items->Add(VectorLista[i]);
			i++;
		}
	}
	};
}