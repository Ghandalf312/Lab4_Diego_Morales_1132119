#pragma once
#include "Pokemon.h"
#include "Lista.h"
#include "Orden.h"
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
	private: System::Windows::Forms::Button^ btnStupid;
	private: System::Windows::Forms::Button^ btnQuick;
	private: System::Windows::Forms::Button^ btnBubble;
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
			this->btnStupid = (gcnew System::Windows::Forms::Button());
			this->btnQuick = (gcnew System::Windows::Forms::Button());
			this->btnBubble = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnMostrar
			// 
			this->btnMostrar->Location = System::Drawing::Point(106, 227);
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
			// btnStupid
			// 
			this->btnStupid->Location = System::Drawing::Point(197, 271);
			this->btnStupid->Name = L"btnStupid";
			this->btnStupid->Size = System::Drawing::Size(75, 23);
			this->btnStupid->TabIndex = 2;
			this->btnStupid->Text = L"Stupid Sort";
			this->btnStupid->UseVisualStyleBackColor = true;
			this->btnStupid->Click += gcnew System::EventHandler(this, &MyForm::BtnStupid_Click);
			// 
			// btnQuick
			// 
			this->btnQuick->Location = System::Drawing::Point(106, 271);
			this->btnQuick->Name = L"btnQuick";
			this->btnQuick->Size = System::Drawing::Size(75, 23);
			this->btnQuick->TabIndex = 3;
			this->btnQuick->Text = L"Quick Sort";
			this->btnQuick->UseVisualStyleBackColor = true;
			this->btnQuick->Click += gcnew System::EventHandler(this, &MyForm::BtnQuick_Click);
			// 
			// btnBubble
			// 
			this->btnBubble->Location = System::Drawing::Point(13, 271);
			this->btnBubble->Name = L"btnBubble";
			this->btnBubble->Size = System::Drawing::Size(75, 23);
			this->btnBubble->TabIndex = 4;
			this->btnBubble->Text = L"Bubble Sort";
			this->btnBubble->UseVisualStyleBackColor = true;
			this->btnBubble->Click += gcnew System::EventHandler(this, &MyForm::BtnBubble_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 306);
			this->Controls->Add(this->btnBubble);
			this->Controls->Add(this->btnQuick);
			this->Controls->Add(this->btnStupid);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->btnMostrar);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
		Lista* MiLista = new Lista();
		Pokemon* MiPokemon = new Pokemon();
		Orden* MiOrden = new Orden();
		//int VectorLista[70];
	private: System::Void BtnMostrar_Click(System::Object^ sender, System::EventArgs^ e) {
		StreamReader^ streamReader = gcnew StreamReader("ListaPokemon.txt");

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
	private: System::Void BtnBubble_Click(System::Object^ sender, System::EventArgs^ e) {
		Stopwatch^ Timer = gcnew Stopwatch();
		Timer->Start();
		//Orden MiOrden;
		Nodo* aux;
		int ValoresLista[70] = { 11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11 };
		int count = 0;
		aux = MiLista->First;

		while (aux != nullptr && ValoresLista[count] == 11)
		{
			ValoresLista[count] = aux->NatNumber.NatNumber;
			aux = aux->siguiente;
			count++;
		}
		//MiOrden->Burbuja(ValoresLista, 70);
	//	Burbuja(ValoresLista, 70);
	// BUBBLE SORT
		int auxB, i, j;

		for (i = 0; i < 70; i++)
		{
			for (j = i + 1; j < 70; j++)
			{
				if (ValoresLista[i] > ValoresLista[j])
				{
					auxB = ValoresLista[i];
					ValoresLista[i] = ValoresLista[j];
					ValoresLista[j] = auxB;
				}
			}
		}



		MiLista->LimpiarLista();
		for (int i = 0; i < 70; i++)
		{
			if (ValoresLista[i] != 11) {
				MiLista->Push(ValoresLista[i]);
			}
		}
		Timer->Stop();
		System::Windows::Forms::MessageBox::Show("Tiempo de ejecución: " + System::Convert::ToString(Timer->Elapsed));
	}


	public: void Burbuja(int A[], int n) {
		int aux, i, j;
		for (i = 0; i < n - 1; i++)
	    {
			for (j = i + 1; j < n - 1; j++)
			{
				if (A[i] > A[j])
				{
					aux = A[i];
					A[i] = A[j];
					A[j] = aux;
				}
			}
		}
	}
private: System::Void BtnQuick_Click(System::Object^ sender, System::EventArgs^ e) {
	Stopwatch^ Timer = gcnew Stopwatch();
	Timer->Start();
	Nodo* aux;
	//int* ValoresLista[70];
	int ValoresLista[70] = { 11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11 };
	int count = 0;
	aux = MiLista->First;

	while (aux != nullptr && ValoresLista[count] == 11)
	{
		ValoresLista[count] = aux->NatNumber.NatNumber;
		aux = aux->siguiente;
		count++;
	}
	MiOrden->Quick(ValoresLista,0,70);

	MiLista->LimpiarLista();
	for (int i = 0; i < 70; i++)
	{
		if (ValoresLista[i] != 11) {
			MiLista->Push(ValoresLista[i]);
		}
	}
	Timer->Stop();
	System::Windows::Forms::MessageBox::Show("Tiempo de ejecución: " + System::Convert::ToString(Timer->Elapsed));
}
private: System::Void BtnStupid_Click(System::Object^ sender, System::EventArgs^ e) {
	Stopwatch^ Timer = gcnew Stopwatch();
	Timer->Start();
	Nodo* aux;
	int ValoresLista[70] = { 11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11 };
	int count = 0;
	aux = MiLista->First;

	while (aux != nullptr && ValoresLista[count] == 11)
	{
		ValoresLista[count] = aux->NatNumber.NatNumber;
		aux = aux->siguiente;
		count++;
	}
	MiOrden->Stupid(ValoresLista, 70);

	MiLista->LimpiarLista();
	for (int i = 0; i < 70; i++)
	{
		if (ValoresLista[i] != 11) {
			MiLista->Push(ValoresLista[i]);
		}
	}
	Timer->Stop();
	System::Windows::Forms::MessageBox::Show("Tiempo de ejecución: " + System::Convert::ToString(Timer->Elapsed));
}
};
}