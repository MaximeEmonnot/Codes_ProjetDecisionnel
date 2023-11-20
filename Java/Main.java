import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;

public class Main {
    public static void main(String[] args) {
        String inputFile = "C:\\Users\\ahmad\\Documents\\Nouveau dossier\\Worldwide-Earthquake_Final.csv"; 
        String outputFile = "C:\\Users\\ahmad\\Documents\\Nouveau dossier\\Worldwide-Earthquake_Final_modif2.csv"; 

        try {
            // Définir un Locale qui utilise le point comme séparateur décimal
            Locale locale = new Locale("en", "US");

            // Créer un format pour les nombres avec ce Locale
            DecimalFormatSymbols symbols = new DecimalFormatSymbols(locale);
            DecimalFormat decimalFormat = new DecimalFormat("0.00", symbols);

            BufferedReader reader = new BufferedReader(new FileReader(inputFile));

            BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));

            // Obtention des en-têtes de colonnes
            String header = reader.readLine();
            List<String> headers = Arrays.asList(header.split("\\|"));

            // Trouver l'index des colonnes "LATITUDE" et "LONGITUDE"
            int latitudeIndex = headers.indexOf("LATITUDE");
            int longitudeIndex = headers.indexOf("LONGITUDE");
            int magnitudeIndex = headers.indexOf("MAGNITUDE");

            // Vérifier si les colonnes ont été trouvées
            if (latitudeIndex == -1 || longitudeIndex == -1 || magnitudeIndex == -1) {
                System.err.println("Les colonnes 'latitude', 'longitude' et 'mag' n'ont pas été trouvées dans l'en-tête.");
                reader.close();
                writer.close();
                return;
            }

            // Écrire l'en-tête modifié dans le fichier de sortie
            String modifiedHeader = String.join("|", headers);
            writer.write(modifiedHeader);
            writer.newLine();

            String line;
            while ((line = reader.readLine()) != null) {
                // Diviser la ligne en parties en utilisant le délimiteur '|'
                String[] parts = line.split("\\|");

                // Vérifier si la ligne contient des données valides
                if (parts.length > latitudeIndex && parts.length > longitudeIndex && parts.length > magnitudeIndex) {
                    try {
                        // Convertir les valeurs de latitude et de longitude en nombres
                        double latitude = Double.parseDouble(parts[latitudeIndex]);
                        double longitude = Double.parseDouble(parts[longitudeIndex]);
                        double magnitude = Double.parseDouble(parts[magnitudeIndex]);

                        // Formater les valeurs avec le format et Locale spécifiés
                        parts[latitudeIndex] = decimalFormat.format(latitude);
                        parts[longitudeIndex] = decimalFormat.format(longitude);
                        parts[magnitudeIndex] = decimalFormat.format(magnitude);

                        String formattedLine = String.join("|", parts);

                        writer.write(formattedLine);
                        writer.newLine();
                    } catch (NumberFormatException e) {
                        System.out.println("Ligne ignorée (NumberFormatException): " + line);
                        writer.write(line);
                        writer.newLine();
                    }
                }
            }

            
            reader.close();
            writer.close();

            System.out.println("Fichier CSV modifié avec succès !");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}