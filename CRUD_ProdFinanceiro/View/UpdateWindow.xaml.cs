using CRUD_ProdFinanceiro.Interface;
using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace CRUD_ProdFinanceiro.View
{
    /// <summary>
    /// Lógica interna para UpdateWindow.xaml
    /// </summary>
    public partial class UpdateWindow : Window
    {
        public UpdateWindow(IProdutoFinanceiro produtoFinanceiro)
        {
            InitializeComponent();
            DataContext = produtoFinanceiro;
        }
    }
}
