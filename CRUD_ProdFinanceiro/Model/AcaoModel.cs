using CRUD_ProdFinanceiro.Interface;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;


namespace CRUD_ProdFinanceiro.Model
{
    public class AcaoModel : INotifyPropertyChanged, IProdutoFinanceiro
    {
        public event PropertyChangedEventHandler PropertyChanged;

        private void OnPropertyChanged(string nomePropriedade)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nomePropriedade));
        }


        public AcaoModel(string mdlNome, string mdlSigla, string mdlSetor, string mdlTipo)
        {
            Nome = mdlNome;
            Sigla = mdlSigla;
            Setor = mdlSetor;
            Tipo = mdlTipo;
        }
        private string _nome;
        private string _sigla;
        private string _setor;
        private string _tipo;

        public string Nome
        {
            get { return _nome; }
            set
            {
                _nome = value;
                OnPropertyChanged("Nome");
            }
        }

        public string Sigla
        {
            get { return _sigla; }
            set
            {
                _sigla = value;
                OnPropertyChanged("Sigla");
            }
        }

        public string Setor
        {
            get { return _setor; }
            set
            {
                _setor = value;
                OnPropertyChanged("Setor");
            }
        }

        public string Tipo
        {
            get { return _tipo; }
            set
            {
                _tipo = value;
                OnPropertyChanged("Tipo");
            }
        }
    }
}
