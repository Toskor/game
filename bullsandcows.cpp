#include "bullsandcows.h"

BullsAndCows::BullsAndCows()
{  
    cin.setCodec( QTextCodec::codecForName("cp866") );
    cout.setCodec( QTextCodec::codecForName("cp866") );
    try {
        database = new SQLiteDB();
    }
    catch (Exception e) {
        cout << e.whatError() << '\n';
        throw (Exception ());
    }

}

void BullsAndCows::game()
{
    using std::vector;

    QString target = database->getTarget();
    target = target.toLower();

    //записываем сколько букв у цели для подсчета коров
    vector< int > lettersOfTarget (33, 0);
    for ( auto letter : target )
        ++lettersOfTarget[ letter.unicode() - 1072 ]; // 1072 номер буквы 'а' в unicode


    cout << QString("Цель : ") << QString(target) << "\n" << flush ;

    cout << QString("Слово загадано\n") << flush;
    int steps = 1;

    while ( true )
    {
        cout << QString("Шаг ") << steps << " " << flush;

        QString enteredWord = cin.readLine();
        enteredWord = enteredWord.toLower();
        enteredWord = enteredWord.trimmed(); // удаляет пробелы вначале и конце

        //заменить IDataBase::checkWord
        if ( database->checkWord ( enteredWord ) )
        {
            if ( enteredWord == target )
            {
                cout << QString("Победа за ") << steps << QString(" ходов\n") << flush;
                break;
            }
              else
            {
                //подсчет и вывод быков и коров
                int bulls = 0, cows = 0;

                for ( int i = 0;
                      i < std::min( target.size(), enteredWord.size() );
                      ++i )
                {
                    if ( target[i] == enteredWord[i] ) ++bulls;
                }

                // подсчет букв в введенном слове
                vector< int > lettersOfEnteredWord (33, 0);
                for ( auto letter : enteredWord )
                    ++lettersOfEnteredWord[ letter.unicode() - 1072 ]; // 1072 номер буквы а в unicode

                for (int k = 0; k < lettersOfTarget.size(); ++k)
                    cows += std::min( lettersOfEnteredWord[k], lettersOfTarget[k] );

                cout << QString("Быки : ") << bulls << QString(" Коровы : ") << cows << "\n" << flush;
            }
            ++steps;
        }
         else
        {
            cout << QString("Слова нет в словаре\n") << flush;
        }

    }
};



