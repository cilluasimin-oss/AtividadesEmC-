#include <iostream>
#include <vector>
#include <string>
using namespace std;


// =============================
// Classe base: Pessoa
// =============================
class Pessoa {
protected:
    string nome;
    int idade;


public:
    Pessoa(string nome, int idade) : nome(nome), idade(idade) {}
    virtual void exibirInfo() const {
        cout << "Nome: " << nome << "\nIdade: " << idade << endl;
    }
    string getNome() const { return nome; }
};


// =============================
// Classe Aluno
// =============================
class Aluno : public Pessoa {
private:
    int matricula;


public:
    Aluno(string nome, int idade, int matricula)
        : Pessoa(nome, idade), matricula(matricula) {}


    void exibirInfo() const override {
        cout << "=== Aluno ===" << endl;
        Pessoa::exibirInfo();
        cout << "Matricula: " << matricula << endl;
    }


    int getMatricula() const { return matricula; }
};


// =============================
// Classe Alunos (sistema de alunos)
// =============================
class Alunos {
private:
    vector<Aluno> lista;


public:
    void adicionar(const Aluno &aluno) {
        lista.push_back(aluno);
    }


    void listar() const {
        cout << "\n=== Lista de Alunos ===" << endl;
        for (const auto &a : lista) {
            a.exibirInfo();
            cout << endl;
        }
    }


    void buscar(int matricula) const {
        bool encontrado = false;
        for (const auto &a : lista) {
            if (a.getMatricula() == matricula) {
                cout << "\nAluno encontrado:" << endl;
                a.exibirInfo();
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
            cout << "\nAluno nao encontrado!" << endl;
    }


    vector<Aluno> getLista() const {
        return lista;
    }
};


// =============================
// Classe Professor
// =============================
class Professor : public Pessoa {
private:
    string disciplina;


public:
    Professor(string nome, int idade, string disciplina)
        : Pessoa(nome, idade), disciplina(disciplina) {}


    void exibirInfo() const override {
        cout << "=== Professor ===" << endl;
        Pessoa::exibirInfo();
        cout << "Disciplina: " << disciplina << endl;
    }


    string getDisciplina() const { return disciplina; }
};


// =============================
// Classe Turma
// =============================
class Turma {
private:
    string codigo;
    Professor professor;
    vector<Aluno> alunos;


public:
    Turma(string codigo, Professor professor)
        : codigo(codigo), professor(professor) {}


    void adicionarAluno(const Aluno &aluno) {
        alunos.push_back(aluno);
    }


    void exibirTurma() const {
        cout << "\n===== Turma " << codigo << " =====" << endl;
        cout << "Professor responsavel:" << endl;
        professor.exibirInfo();
        cout << "\n--- Alunos ---" << endl;
        for (const auto &a : alunos) {
            a.exibirInfo();
            cout << endl;
        }
    }


    string getCodigo() const { return codigo; }
};


// =============================
// Classe Setor
// =============================
class Setor {
private:
    string nome;
    Pessoa responsavel;


public:
    Setor(string nome, Pessoa responsavel)
        : nome(nome), responsavel(responsavel) {}


    void exibirSetor() const {
        cout << "\n=== Setor: " << nome << " ===" << endl;
        cout << "Responsavel: " << responsavel.getNome() << endl;
    }


    string getNome() const { return nome; }
};


// =============================
// Classe Secretaria (controladora do sistema)
// =============================
class Secretaria {
private:
    vector<Turma> turmas;
    Alunos alunos;
    vector<Professor> professores;
    vector<Setor> setores;


public:
    // Cadastro
    void cadastrarAluno(const Aluno &aluno) { alunos.adicionar(aluno); }
    void cadastrarProfessor(const Professor &professor) { professores.push_back(professor); }
    void criarTurma(const Turma &turma) { turmas.push_back(turma); }
    void cadastrarSetor(const Setor &setor) { setores.push_back(setor); }


    // Listagens
    void listarAlunos() const { alunos.listar(); }


    void listarTurmas() const {
        cout << "\n=== Turmas Cadastradas ===" << endl;
        for (const auto &t : turmas)
            t.exibirTurma();
    }


    void listarSetores() const {
        cout << "\n=== Setores da Escola ===" << endl;
        for (const auto &s : setores)
            s.exibirSetor();
    }


    // Busca
    void buscarAluno(int matricula) const { alunos.buscar(matricula); }
};


// =============================
// Função principal
// =============================
int main() {
    Secretaria secretaria;


    // Professores
    Professor prof1("Katia", 52, "Matematica");
    Professor prof2("Anusa", 44, "Historia");
    Professor prof3("Paulo", 45, "Ingles");
    Professor prof4("Cristiane", 44, "Portugues");
    Professor prof5("Denilson", 40, "Geografia");
    Professor prof6("Deyla", 53, "Sociologia");
    Professor prof7("Deyla", 53, "Filosofia");
    Professor prof8("Cleise", 50, "Biologia");
    Professor prof9("Andresa", 51, "Artes");
    Professor prof10("Andresa", 51, "Educacao Fisica");
    Professor prof11("Lucas", 37, "Fisica");
    Professor prof12("Lorena", 39, "Quimica");
    Professor prof13("Paulo", 45, "Linguagens");
    Professor prof14("Katia", 52, "Letramento matematico");
    Professor prof15("Priscila", 38, "Linguagem de Programacao");


    secretaria.cadastrarProfessor(prof1);
    secretaria.cadastrarProfessor(prof2);
    secretaria.cadastrarProfessor(prof3);
    secretaria.cadastrarProfessor(prof4);
    secretaria.cadastrarProfessor(prof5);
    secretaria.cadastrarProfessor(prof6);
    secretaria.cadastrarProfessor(prof7);
    secretaria.cadastrarProfessor(prof8);
    secretaria.cadastrarProfessor(prof9);
    secretaria.cadastrarProfessor(prof10);
    secretaria.cadastrarProfessor(prof11);
    secretaria.cadastrarProfessor(prof12);
    secretaria.cadastrarProfessor(prof13);
    secretaria.cadastrarProfessor(prof14);
    secretaria.cadastrarProfessor(prof15);
    

    // Alunos
    Aluno a1("Ana Ester", 16, 101);
    Aluno a2("Ana Julia", 16, 102);
    Aluno a3("Argenis", 15, 103);
    Aluno a4("Bruno", 15, 104);
    Aluno a5("Edma", 15, 105);
    Aluno a6("Francinei", 15, 106);
    Aluno a7("Francisco", 16, 105);
    Aluno a8("Gustavo", 15, 106);
    Aluno a9("Helio", 15, 107);
    Aluno a10("Henrique", 16, 108);
    Aluno a11("Jhonata", 15, 109);
    Aluno a12("Joao", 16, 110);
    Aluno a13("John", 15, 111);
    Aluno a14("Julita", 15, 112);
    Aluno a15("Leonardo", 16, 113);
    Aluno a16("Maria Eduarda", 16, 114);
    Aluno a17("Maria Luiza", 16, 115);
    Aluno a18("Miguel", 16, 116);
    Aluno a19("Nayanne", 16, 117);
    Aluno a20("Nicole", 16, 118);
    Aluno a21("Otavio", 17, 119);
    Aluno a22("Shymenne", 16, 120);
    Aluno a23("Vitoria", 16, 121);
    Aluno a24("Yasmin", 16, 122);

    secretaria.cadastrarAluno(a1);
    secretaria.cadastrarAluno(a2);
    secretaria.cadastrarAluno(a3);
    secretaria.cadastrarAluno(a4);
    secretaria.cadastrarAluno(a5);
    secretaria.cadastrarAluno(a6);
    secretaria.cadastrarAluno(a7);
    secretaria.cadastrarAluno(a8);
    secretaria.cadastrarAluno(a9);
    secretaria.cadastrarAluno(a10);
    secretaria.cadastrarAluno(a11);
    secretaria.cadastrarAluno(a12);
    secretaria.cadastrarAluno(a13);
    secretaria.cadastrarAluno(a14);
    secretaria.cadastrarAluno(a15);
    secretaria.cadastrarAluno(a16);
    secretaria.cadastrarAluno(a17);
    secretaria.cadastrarAluno(a18);
    secretaria.cadastrarAluno(a19);
    secretaria.cadastrarAluno(a20);
    secretaria.cadastrarAluno(a21);
    secretaria.cadastrarAluno(a22);
    secretaria.cadastrarAluno(a23);
    secretaria.cadastrarAluno(a24);


    // Turmas


    Turma t1("A1", prof1);
    t1.adicionarAluno(a1);
    t1.adicionarAluno(a2);
    t1.adicionarAluno(a3);
    t1.adicionarAluno(a4);
    t1.adicionarAluno(a5);
    t1.adicionarAluno(a6);
    t1.adicionarAluno(a7);
    t1.adicionarAluno(a8);
    t1.adicionarAluno(a9);
    t1.adicionarAluno(a10);
    t1.adicionarAluno(a11);
    t1.adicionarAluno(a12);

    Turma t2("B2", prof2);

    t2.adicionarAluno(a13);
    t2.adicionarAluno(a14);
    t2.adicionarAluno(a15);
    t2.adicionarAluno(a16);
    t2.adicionarAluno(a17);
    t2.adicionarAluno(a18);
    t2.adicionarAluno(a19);
    t2.adicionarAluno(a20);
    t2.adicionarAluno(a21);
    t2.adicionarAluno(a22);
    t2.adicionarAluno(a23);
    t2.adicionarAluno(a24);

    secretaria.criarTurma(t1);
    secretaria.criarTurma(t2);


    // Setores
    Pessoa func1("Fernanda Alves", 32);
    Pessoa func2("Ricardo Lima", 45);
    Setor s1("Secretaria", func1);
    Setor s2("Biblioteca", func2);
    secretaria.cadastrarSetor(s1);
    secretaria.cadastrarSetor(s2);


    // Exibições
    secretaria.listarAlunos();
    secretaria.buscarAluno(102);
    secretaria.listarTurmas();
    secretaria.listarSetores();


    return 0;
}


