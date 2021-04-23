using CRUD_ProdFinanceiro.Command;
using CRUD_ProdFinanceiro.Interface;
using CRUD_ProdFinanceiro.Model;
using CRUD_ProdFinanceiro.View;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;
using System.Windows.Input;

namespace CRUD_ProdFinanceiro.ViewModel
{
    public class ProdutoFinanceiroViewModel
    {
        public ObservableCollection<IProdutoFinanceiro> ProdutoFinanceiro { get; private set; }


        public ICommand CreateProdutoFinanceiroCommand { get; private set; }
        public ICommand ReadProdutoFinanceiroCommand { get; private set; }
        public ICommand UpdateProdutoFinanceiroCommand { get; private set; }
        public ICommand DeleteProdutoFinanceiroCommand { get; private set; }

        private string _sigla;
        private string _nome;
        private string _setor;
        private string _tipo;
        public string Sigla
        {
            get { return _sigla; }
            set { _sigla = value; }
        }
        public string Nome
        {
            get { return _nome; }
            set { _nome = value; }
        }
        public string Setor
        {
            get { return _setor; }
            set { _setor = value; }
        }
        public string Tipo
        {
            get { return _tipo; }
            set { _tipo = value; }
        }


        public ProdutoFinanceiroViewModel()
        {
            ProdutoFinanceiro = new ObservableCollection<IProdutoFinanceiro>();
            this.MyCommands();
        }

        private void MyCommands()
        {
            CreateProdutoFinanceiroCommand = new RelayCommand(CreateProdutoFinanceiro, CreateProdutoFinanceiroCanUse);
            ReadProdutoFinanceiroCommand = new RelayCommand(ReadProdutoFinanceiro, ReadProdutoFinanceiroCanUse);
            UpdateProdutoFinanceiroCommand = new RelayCommand(UpdateProdutoFinanceiro, UpdateProdutoFinanceiroCanUse);
            DeleteProdutoFinanceiroCommand = new RelayCommand(DeleteProdutoFinanceiro, DeleteProdutoFinanceiroCanUse);
        }

        public void CreateProdutoFinanceiro(object objRelayCommand)
        {
            
            if(Tipo == "Ação")
            {
                ProdutoFinanceiro.Add(new AcaoModel(Nome, Sigla, Setor, Tipo));
            }
            else if(Tipo == "Fundo")
            {
                ProdutoFinanceiro.Add(new FundoModel(Nome, Sigla, Setor, Tipo));
            }
            
        }
        public bool CreateProdutoFinanceiroCanUse(object objRelayCommand)
        {
            return true;
        }

        public void ReadProdutoFinanceiro(object objRelayCommand)
        {

        }
        public bool ReadProdutoFinanceiroCanUse(object objRelayCommand)
        {
            return true;
        }

        public void UpdateProdutoFinanceiro(object objRelayCommand)
        {
            UpdateWindow updateWindow = new UpdateWindow((IProdutoFinanceiro)objRelayCommand);
            updateWindow.Show();

        }
        public bool UpdateProdutoFinanceiroCanUse(object objRelayCommand)
        {
            if (objRelayCommand == null)
                return false;
            return true;
        }

        public void DeleteProdutoFinanceiro(object objRelayCommand)
        {
            ProdutoFinanceiro.Remove((IProdutoFinanceiro)objRelayCommand);

        }
        public bool DeleteProdutoFinanceiroCanUse(object objRelayCommand)
        {
            if (objRelayCommand == null)
                return false;
            return true;
        }
    }
}
